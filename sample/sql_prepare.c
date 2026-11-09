/* sqlite3_prepareを使った場合の挿入・削除・更新 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sqlite3.h>

#define SQL_SWITCH 0		// 操作切替
#define LOOP_COUNT 1000000

int main(void){
	int ret = 0;						// 返り値格納
	sqlite3 *conn = NULL;				// データベースのポインタ
	char *err_msg = NULL;				// エラーメッセージ格納
	char sql[256];						// SQL格納
	int i = 0;
	memset(sql, 0, sizeof(sql));

	/* DBを開く */
	ret = sqlite3_open(
		"./insert_test.db",
		&conn
		);
	if(SQLITE_OK != ret ){
		exit(-1);
	}
	sqlite3_busy_timeout(conn, 5000);	//トランザクションがBUSY状態の場合の待ち時間を設定

	switch(SQL_SWITCH){
		case 0:		// INSERT
			snprintf( &sql[0], sizeof(sql)-1, "insert into tb1 values(?)");	
			break;
		case 1:		// DELETE
			snprintf( &sql[0], sizeof(sql)-1, "delete from tb1 where id = ?");
			break;
		case 2:		// UPDATE
			snprintf( &sql[0], sizeof(sql)-1, "update tb1 set id = ? where id = ?");
			break;
		case 3:		// SELECT
			snprintf( &sql[0], sizeof(sql)-1, "select id from tb1 where id = ?");
			break;
	}
	sqlite3_stmt *statement = NULL;
	ret = sqlite3_prepare(conn, sql, strlen(sql), &statement, NULL);
	if(SQLITE_OK != ret){
		printf("ERROR:sqlite3_prepare.\n");
		sqlite3_finalize(statement);
		sqlite3_close(conn);
		exit(-1);
	}
	/* トランザクションを開始 */
	printf("Start Transaction.\n");
	ret = sqlite3_exec(conn, "BEGIN", NULL, NULL, &err_msg);
	if(SQLITE_OK != ret ){
		sqlite3_close(conn);
		exit(-1);
	}
	if(SQL_SWITCH == 0 || SQL_SWITCH == 1){
		/* INSERT,DELETEの場合 */
		for(i = 0; i < LOOP_COUNT; i++){
			sqlite3_reset(statement);
			ret = sqlite3_bind_int(statement, 1, i);
			if(SQLITE_OK != ret){
				printf("ERROR:sqlite3_bind_int.%d\n",i);
				sqlite3_finalize(statement);
				sqlite3_close(conn);
				exit(-1);
			}
			if(SQLITE_ERROR == sqlite3_step(statement)){
				break;
			}
		}
	}else if(SQL_SWITCH == 2){
		/* UPDATEの場合 */
		for(i = 0; i < LOOP_COUNT; i++){
			sqlite3_reset(statement);
			ret = sqlite3_bind_int(statement, 1, i);
			ret = sqlite3_bind_int(statement, 2, i+1);
			if(SQLITE_OK != ret){
				printf("ERROR:sqlite3_bind_int.%d\n",i);
				sqlite3_finalize(statement);
				sqlite3_close(conn);
				exit(-1);
			}
			if(SQLITE_ERROR == sqlite3_step(statement)){
				break;
			}
		}
	}else{
		/* SELECTの場合 */
		ret = sqlite3_bind_int(statement, 1, 1);
		if(SQLITE_OK != ret){
			printf("ERROR:sqlite3_bind_int.%d\n",i);
			sqlite3_finalize(statement);
			sqlite3_close(conn);
			exit(-1);
		}
		while(SQLITE_ROW == sqlite3_step(statement)){		// 行単位で順に選択結果を取得
			int tmp = sqlite3_column_int(statement, 0);	// 行の１つ目の要素をtmpに格納
			printf("id = %d\n", tmp);						// １つ目の要素を表示
		}
	}

	sqlite3_finalize(statement);
	/* トランザクションを終了 */
	ret = sqlite3_exec(conn, "COMMIT", NULL, NULL, &err_msg);
	if(SQLITE_OK != ret){
		sqlite3_close(conn);
		exit(-1);
	}
	printf("End Transaction.\n");

	/* DBを閉じる */
	ret = sqlite3_close( conn );
	if( SQLITE_OK != ret ){
		printf("%s\n", err_msg );
		sqlite3_free( err_msg );
		exit(-1);
	}
	return 0;
}


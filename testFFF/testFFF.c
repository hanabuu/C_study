/*
 ============================================================================
 Name        : testFFF.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "fff.h"
DEFINE_FFF_GLOBALS;


FAKE_VOID_FUNC(DISPLAY_init);

TEST_F(GreeterTest, init_initialises_display){
	UI_init();
	ASSERT_EQ(DISPLAY_init_fake.call_count, 1);
}

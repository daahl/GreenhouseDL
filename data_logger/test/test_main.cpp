#include <Arduino.h>
#include <unity.h>

void setUp(void){

}

void tearDown(void){

}

// Test that the test is working
void test_unit_test_pass(void){
    TEST_ASSERT_EQUAL(1, 1);
}
void test_unit_test_fail(void){
    TEST_ASSERT_EQUAL(0, 1);
}

void setup(){
    delay(2000);
    UNITY_BEGIN();

    RUN_TEST(test_unit_test_pass);
    RUN_TEST(test_unit_test_fail);

    UNITY_END();
}

void loop(){

}
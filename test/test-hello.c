#include <stdint.h>
#include <unity.h>
#include <zephyr.h>
#include "drivers/gpio.h"
#include "header.h"

#define LED0_NODE DT_ALIAS(led0)
#define LED0	DT_GPIO_LABEL(LED0_NODE, gpios)
#define PIN	DT_GPIO_PIN(LED0_NODE, gpios)
#define FLAGS	DT_GPIO_FLAGS(LED0_NODE, gpios)



void setUp(void) 
{
  // turn on LEDs?
  //gpio_pin_set(dev, PIN, (int)led_is_on);
  
  
}

void tearDown(void) 
{
    //turn off LEDs?
}

void test_variable_assignment()
{
    int x = 1;
    TEST_ASSERT_TRUE_MESSAGE(x == 1,"Variable assignment failed.");
}

void test_multiplication(void)
{
    int x = 5;
    int y = 6;
    int z = x * y;
    TEST_ASSERT_TRUE_MESSAGE(z == 30, "Multiplication of two integers returned incorrect value.");
}


void myTest()
{

  // int x;
  // int *y = &x;
  // int **z = &y;

    const struct device *dev; 
     dev = device_get_binding(LED0);
    gpio_pin_t pin = PIN;
	gpio_pin_configure(dev, pin, GPIO_OUTPUT_ACTIVE | FLAGS);
    bool LED = 0;
    
    myFunc(dev, &LED, pin);
    int result = gpio_pin_get(dev, pin);    
    TEST_ASSERT_TRUE_MESSAGE(result==1, "pin is not 1");
    TEST_ASSERT_TRUE_MESSAGE(LED==0, "pin should be 1, and it is not");
   

	
	
    
}
int main (void)
{
    UNITY_BEGIN();
    RUN_TEST(test_variable_assignment);
    RUN_TEST(test_multiplication);
    RUN_TEST(myTest);
    return UNITY_END();
}
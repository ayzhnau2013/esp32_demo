#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

static const char *TAG = "MAIN";
#define GPIO_STACK_SIZE 2048
#define PIN_DIGITAL_OUTPUT GPIO_NUM_21

void gpio_task(void* pvParameters) 
{
    uint32_t level_counter = 0;
    gpio_config_t output = {
        .intr_type = GPIO_INTR_DISABLE,
        .pin_bit_mask = 1UL << PIN_DIGITAL_OUTPUT,
        .mode = GPIO_MODE_INPUT
    };

    gpio_config(&output);
    while(true) {
        ESP_LOGI(TAG,"level_counter: %d", level_counter);
        int current_level = level_counter & 0x01;
        ESP_LOGI(TAG,"currnt_level: %d",current_level);
        gpio_set_level(PIN_DIGITAL_OUTPUT,current_level);
        vTaskDelay(5000 / portTICK_PERIOD_MS);
        level_counter++;
    }
}

void app_main() {
    TaskHandle_t* gpio_task_handle = NULL;
    xTaskCreate(gpio_task,"gpio_task",GPIO_STACK_SIZE,NULL,tskIDLE_PRIORITY + 1, &gpio_task_handle);
}
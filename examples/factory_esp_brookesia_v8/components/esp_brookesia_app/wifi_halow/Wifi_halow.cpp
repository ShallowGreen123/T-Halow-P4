/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "Wifi_halow.hpp"
#include "esp_log.h"
#include "t_halow_p4_board.h"

#include "ui/ui.h"
#include "esp_brookesia_versions.h"

// #include "esp-bsp.h"

using namespace std;

LV_IMG_DECLARE(img_wifi_halow);

#define APP_NAME "WIFI Halow"

#define LVGL_FLUSH_BUF 1200

static lv_timer_t *halow_timer = NULL;

TaskHandle_t halwo_echo_task111_handle = NULL;

void halow_timer_cb(lv_timer_t *t);

WIFI_halow::WIFI_halow(bool use_status_bar, bool use_navigation_bar) : ESP_Brookesia_PhoneApp(APP_NAME, &img_wifi_halow, false, use_status_bar, use_navigation_bar)
{
}

WIFI_halow::WIFI_halow() : ESP_Brookesia_PhoneApp(APP_NAME, &img_wifi_halow, false)
{
}

WIFI_halow::~WIFI_halow()
{
    ESP_BROOKESIA_LOGI("Destroy(@0x%p)", this);
}

bool WIFI_halow::run(void)
{
    // this->_core.
    ESP_BROOKESIA_LOGI("Run");

    ui_halow_init();

    halow_echo_resume();
    
    halow_timer = lv_timer_create(halow_timer_cb, 10, NULL);

    return true;
}

bool WIFI_halow::back(void)
{
    ESP_BROOKESIA_LOGI("Back");

    // If the app needs to exit, call notifyCoreClosed() to notify the core to close the app
    ESP_BROOKESIA_CHECK_FALSE_RETURN(notifyCoreClosed(), false, "Notify core closed failed");

    return true;
}

bool WIFI_halow::close(void)
{
    ESP_BROOKESIA_LOGI("Close");

    /* Do some operations here if needed */
    halow_echo_suspend();

    if (halow_timer)
    {
        lv_timer_del(halow_timer);
        halow_timer = NULL;
    }
    return true;
}

bool WIFI_halow::init()
{
    ESP_BROOKESIA_LOGI("Init");

    /* Do some initialization here if needed */

    halow_init();

    return true;
}

void halow_timer_cb(lv_timer_t *t)
{
    size_t item_size;
    uint8_t *item;
    static char merge_buf[LVGL_FLUSH_BUF];
    static uint32_t text_sun_len = 0;
    int total = 0;

    while ((item = (uint8_t *)xRingbufferReceiveUpTo(
                log_rb, &item_size, 0, 128)) != NULL) {

        if (total + item_size >= LVGL_FLUSH_BUF)
            break;

        memcpy(&merge_buf[total], item, item_size);
        total += item_size;

        vRingbufferReturnItem(log_rb, item);
    }

    if (total > 0) {
        text_sun_len += total;
        if(text_sun_len > 1000) {
            text_sun_len = 0;
            lv_textarea_set_text(ui_halowSetting_halowDebugTextArea, "");
        }
        merge_buf[total] = '\0';
        lv_textarea_add_text(ui_halowSetting_halowDebugTextArea, merge_buf);
    }
}

// bool WIFI_halow::deinit()
// {
//     ESP_BROOKESIA_LOGD("Deinit");

//     /* Do some deinitialization here if needed */

//     return true;
// }

// bool WIFI_halow::pause()
// {
//     ESP_BROOKESIA_LOGD("Pause");

//     /* Do some operations here if needed */

//     return true;
// }

// bool WIFI_halow::resume()
// {
//     ESP_BROOKESIA_LOGD("Resume");

//     /* Do some operations here if needed */

//     return true;
// }

// bool WIFI_halow::cleanResource()
// {
//     ESP_BROOKESIA_LOGD("Clean resource");

//     /* Do some cleanup here if needed */

//     return true;
// }

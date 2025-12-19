/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "Wifi_halow.hpp"
#include "esp_log.h"

using namespace std;

LV_IMG_DECLARE(img_wifi_halow);

#define APP_NAME                "WIFI Halow"

WIFI_halow::WIFI_halow(bool use_status_bar, bool use_navigation_bar):
    ESP_Brookesia_PhoneApp(APP_NAME, &img_wifi_halow, true, use_status_bar, use_navigation_bar)
{
}

WIFI_halow::WIFI_halow():
    ESP_Brookesia_PhoneApp(APP_NAME, &img_wifi_halow, true)
{
}

WIFI_halow::~WIFI_halow()
{
    ESP_BROOKESIA_LOGD("Destroy(@0x%p)", this);
}

bool WIFI_halow::run(void)
{
    ESP_BROOKESIA_LOGD("Run");

    // Create all UI resources here
    // ESP_BROOKESIA_CHECK_FALSE_RETURN(phone_app_simple_conf_main_init(), false, "Main init failed");
    lv_obj_t *label = lv_label_create(lv_scr_act());
    ESP_BROOKESIA_CHECK_NULL_RETURN(label, false, "Create label failed");
    lv_label_set_text(label, "To be added ...");
    lv_obj_center(label);
    lv_obj_set_style_text_font(label, LV_FONT_DEFAULT, 0);

    return true;
}

bool WIFI_halow::back(void)
{
    ESP_BROOKESIA_LOGD("Back");

    // If the app needs to exit, call notifyCoreClosed() to notify the core to close the app
    ESP_BROOKESIA_CHECK_FALSE_RETURN(notifyCoreClosed(), false, "Notify core closed failed");

    return true;
}

// bool WIFI_halow::close(void)
// {
//     ESP_BROOKESIA_LOGD("Close");

//     /* Do some operations here if needed */

//     return true;
// }

// bool WIFI_halow::init()
// {
//     ESP_BROOKESIA_LOGD("Init");

//     /* Do some initialization here if needed */

//     return true;
// }

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

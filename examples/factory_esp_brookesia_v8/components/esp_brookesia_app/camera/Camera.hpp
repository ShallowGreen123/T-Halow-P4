#pragma once

#include "lvgl.h"
#include "esp_brookesia.hpp"


class Camera: public ESP_Brookesia_PhoneApp {
public:

    Camera(bool use_status_bar, bool use_navigation_bar);
    Camera();
    ~Camera();

    bool run(void) override;
    bool back(void) override;
    // bool close(void) override;

    // bool init(void) override;
    // bool init(void) override;

    // bool pause(void) override;
    // bool resume(void) override;
    // bool cleanResource(void) override;
};

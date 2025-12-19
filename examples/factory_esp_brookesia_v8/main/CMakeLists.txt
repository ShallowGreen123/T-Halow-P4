idf_component_register(
SRCS 
    "factory_esp_brookesia.cpp"
INCLUDE_DIRS 
    "."
    "esp_ui_phone_568_1232_stylesheet"
    )

idf_build_set_property(COMPILE_OPTIONS
    "-Wno-missing-field-initializers"
    APPEND)


# 使用音频需要先下载一次文件系统
# spiffs_create_partition_image(storage ../spiffs FLASH_IN_PROJECT)
<h1 align = "center">T-Halow-P4 debug</h1>

### ESP-IDF Visual Studio Code
1. 安装 [Visual Studio Code](https://code.visualstudio.com/Download) ，根据你的系统类型选择安装。

2. 打开 VisualStudioCode 软件侧边栏的“扩展”（或者使用<kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>X</kbd>打开扩展），搜索“ESP-IDF”扩展并下载。

3. 在安装扩展的期间，使用git命令克隆仓库

        git clone -b debug --recursive https://github.com/Xinyuan-LilyGO/T-Halow-P4.git

    克隆时候需要同时加上“--recursive”，如果克隆时候未加上那么之后使用的时候需要初始化一下子模块

        git submodule update --init --recursive

4. 下载安装 [ESP-IDF v5.4.1](https://dl.espressif.cn/dl/esp-idf/?idf=4.4)，记录一下安装路径，打开之前安装好的“ESP-IDF”扩展打开“配置 ESP-IDF 扩展”，选择“USE EXISTING SETUP”菜单，选择“Search ESP-IDF in system”栏，正确配置之前记录的安装路径：
   - **ESP-IDF directory (IDF_PATH):** `你的安装路径xxx\Espressif\frameworks\esp-idf-v5.4`  
   - **ESP-IDF Tools directory (IDF_TOOLS_PATH):** `你的安装路径xxx\Espressif`  
    点击右下角的“install”进行框架安装。

5. 点击 Visual Studio Code 底部菜单栏的 ESP-IDF 扩展菜单“SDK 配置编辑器”，在搜索栏里搜索“Select the example to build”字段，选择你所需要编译的项目，再在搜索栏里搜索“Select the camera type”字段，选择你的板子板载的摄像头类型，点击保存。

6. 点击 Visual Studio Code 底部菜单栏的“设置乐鑫设备目标”，选择**ESP32P4**，点击底部菜单栏的“构建项目”，等待构建完成后点击底部菜单栏的“选择要使用的端口”，之后点击底部菜单栏的“烧录项目”进行烧录程序。

<p align="center" width="100%">
    <img src="image/1.jpg" alt="example">
</p>

## Halow API


1、基础组网API

~~~c
int hgic_raw_set_ssid(char *ssid);

int hgic_raw_set_key_mgmt(char *key_mgmt);

int hgic_raw_set_wpa_psk(char *psk);

int hgic_raw_set_freq_range(int freq_start, int freq_end, int bss_bw);

int hgic_raw_set_bss_bw(char bss_bw);

int hgic_raw_set_acs(char acs, char acs_tmo);

int hgic_raw_set_mac(char *mac);

int hgic_raw_set_chan_list(int *chan_list, int count);

int hgic_raw_set_mode(char *mode);

int hgic_raw_set_pairing(char enable);

int hgic_raw_set_pair_autostop(char enable);

~~~

2、组网高级 API

~~~c
int hgic_raw_set_txpower(int power);

int hgic_raw_set_tx_mcs(char tx_mcs);

int hgic_raw_set_bss_max_idle(int bss_max_idle);

int hgic_raw_set_channel(int channel);

int hgic_raw_unpair(char *mac);

int hgic_raw_set_paired_stas(char *stas, int len);

int hgic_raw_set_auto_chswitch(char enable);

int hgic_raw_set_primary_chan(char primary_chan);

int hgic_raw_set_mac_filter_en(char enable);

int hgic_raw_set_supper_pwr(char enable);

int hgic_raw_set_acktmo(int acktmo);

int hgic_raw_set_beacon_int(int beacon_int);

int hgic_raw_set_heartbeat_int(int heartbeat_int);

int hgic_raw_set_ap_chan_switch(char chan_index, char counter);

int hgic_raw_set_agg_cnt(char agg_cnt);

int hgic_raw_set_ap_hide(char en);

int hgic_raw_set_max_txcnt(char txcnt);

int hgic_raw_set_dup_filter_en(char en);

int hgic_raw_set_dis_1v1_m2u(char dis);

int hgic_raw_set_kick_assoc(char en);

int hgic_raw_set_connect_paironly(char en);

int hgic_raw_disassoc_sta(char *addr);

int hgic_raw_set_sta_freqinfo(char *addr, struct hgic_freqinfo* freqinfo);

int hgic_raw_set_cust_isolation(char en);

~~~

3、状态查询 API

~~~c
int hgic_raw_get_fwinfo(void);

int hgic_raw_get_connect_state(void);

int hgic_raw_get_mode(void);

int hgic_raw_get_sta_list(void);

int hgic_raw_get_bgrssi(char chan_index);

int hgic_raw_scan(void);

int hgic_raw_get_scan_list(void);

int hgic_raw_get_temperature(void);

int hgic_raw_get_ssid(void);

int hgic_raw_get_bssid(char *bssid);

int hgic_raw_get_wpa_psk(void);

int hgic_raw_get_sta_count(void);

int hgic_raw_get_txpower(void);

int hgic_raw_get_aggcnt(void);

int hgic_raw_get_freq_range(void);

int hgic_raw_get_chan_list(void);

int hgic_raw_get_bss_bw(void);

int hgic_raw_get_key_mgmt(void);

int hgic_raw_get_module_type(void);

int hgic_raw_get_dhcpc_result(void);

int hgic_raw_get_disassoc_reason(void);

int hgic_raw_get_rtc(void);

int hgic_raw_get_center_freq(void);

int hgic_raw_get_wakeup_reason(void);
~~~

4、低功耗相关 API

~~~c
int hgic_raw_sleep(char sleep);

int hgic_raw_set_wkio_mode(char wkio_mode);

int hgic_raw_set_dtim_period(int dtim_period);

int hgic_raw_set_ps_mode(char ps_mode);

int hgic_raw_set_ps_connect(char period, char roundup);

int hgic_raw_set_wait_psmode(char mode);

int hgic_raw_set_standby(char channel, int period_ms);

int hgic_raw_set_aplost_time(int aplost_time);

int hgic_raw_set_reassoc_wkhost(char enable);

int hgic_raw_set_wakeup_io(char wakeup_io, char edge);

int hgic_raw_set_autosleep_time(char autosleep_time);

int hgic_raw_set_dcdc13(char enable);

int hgic_raw_set_ap_psmode_en(char enable);

int hgic_raw_set_pa_pwrctl_dis(char disable);

int hgic_raw_set_dis_psconnect(char disable);

int hgic_raw_set_wkdata_save_en(char enable);

int hgic_raw_get_wkdata_buff(void);

int hgic_raw_set_wkhost_reasons(char *reasons, int count);

int hgic_raw_wakeup_sta(char *mac);

int hgic_raw_set_ps_heartbeat(unsigned int ipaddr, unsigned int dport, unsigned int period, unsigned int hb_tmo);

int hgic_raw_set_heartbeat_resp(char *heartbeat_resp, int len);

int hgic_raw_set_ps_wkdata(char *ps_wkdata, int len);

int hgic_raw_set_wkdata_mask(unsigned short offset, unsigned char *mask, int mask_len)
~~~

5、组播模式 API

~~~c
int hgic_raw_join_group(char *group_addr, char aid);

int hgic_raw_set_mcast_txparam(char dupcnt, char txbw, char txmcs, char clearch)
~~~

6、中继模式 API

~~~c
int hgic_raw_set_r_ssid(char *r_ssid);

int hgic_raw_set_r_psk(char *r_psk);
~~~

7、漫游功能 API

~~~c
int hgic_raw_set_roaming(char enable, char same_freq);
~~~

8、双天线功能 API

~~~c
int hgic_raw_set_ant_auto(char en);

int hgic_raw_set_dual_ant(char en);

int hgic_raw_set_ant_sel(char en);

int hgic_raw_get_ant_sel(void);

~~~

9、调试功能 API

~~~c
int hgic_raw_set_dbginfo(char enable);

int hgic_raw_set_sysdbg(char *sysdbg);

int hgic_raw_set_assert_holdup(char assert_holdup);

int hgic_raw_set_atcmd(char *atcmd);
~~~

10、其他 API

~~~c
int hgic_raw_open(void);

int hgic_raw_close(void);

int hgic_raw_save(void);

int hgic_raw_set_auto_save(char enable);

int hgic_raw_set_radio_onoff(char on);

int hgic_raw_set_rtc(char on);

int hgic_raw_set_ether_type(unsigned short ether_type);

int hgic_raw_set_load_def(char reset_en);

int hgic_raw_mcu_reset(void);

int hgic_raw_start_assoc(void);

int hgic_raw_send_customer_mgmt(char *dest, struct hgic_tx_info *info, char *data, int len);


~~~
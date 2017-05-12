/*
 * hwconfig.h
 *
 *  Created on: Jan 17, 2017
 *      Author: a.bilinets@gmail.com
 */

#ifndef SRC_HWCONFIG_H_
#define SRC_HWCONFIG_H_

#include <stdint.h>
#include <stdbool.h>

#define HWCONFIG_PATH "/etc/hwconfig"
#ifdef EMULATOR
#warning "Build to Linux...Redefine Config path!"
#undef HWCONFIG_PATH
#define HWCONFIG_PATH "./system/config/hwconfig"
#endif

typedef enum {
	PLATFORM_WRONG = 0,
	PLATFORM_MX6SL,
	PLATFORM_A13 = 14,
	PLATFORM_B288 = 16,
} platform_id_t;

typedef enum {
	DEVICE_WRONG = 0,
	DEVICE_631 = 5,
	DEVICE_641 = 17,
	DEVICE_627 = 18,
	DEVICE_614 = 19,
	DEVICE_615 = 20,
} device_id_t;

// ================ display and epd controller ==============

typedef enum {
	DISPLAY_6INCH = 0,
	DISPLAY_5INCH,
	DISPLAY_8INCH,
	DISPLAY_9INCH,
	DISPLAY_6INCH_758, // display 1024x758 6" HD
	DISPLAY_8TRITON, // display 1800x800 8"
	DISPLAY_8INCH_1200, // display 1600x1200 8"
	DISPLAY_4INCH_480_800 = 8, // display 480x800 4.3"
	DISPLAY_6INCH_1072_1448, // display 1448x1072 6"
} display_id_t;

typedef enum {
	EPDC_NONE = 0,
	EPDC_IMX = 3,
	EPDC_ALLWINNER_A13 = 5,
} epdc_id_t;

//======= input devices ============

typedef enum {
	KEYBOARD_NTX600 = 0,
	KEYBOARD_POCKET360,
	KEYBOARD_COOKIE,
	KEYBOARD_DIGITEKA,
	KEYBOARD_EP1234,
	KEYBOARD_POCKET611,
	KEYBOARD_POCKET613,
	KEYBOARD_EP7,
	KEYBOARD_POCKET515,
	KEYBOARD_POCKET624,
	KEYBOARD_POCKET650,
	KEYBOARD_POCKET840,
	KEYBOARD_POCKET630,
	KEYBOARD_POCKET420,
	KEYBOARD_POCKET620,
	KEYBOARD_POCKET631,
	KEYBOARD_POCKET641, //like 626, but without standart power button. Power button is KEY_MENU
} keyboard_id_t;

typedef enum {
	TOUCHPANEL_NONE = 0,
	TOUCHPANEL_IR_zFORCE = 4, //631
	TOUCHPANEL_ELAN_eKTF2227 = 8, //626, 641
	TOUCHPANEL_ELAN_eKTF2232 = 16, //627
} touchpanel_id_t;

typedef enum {
	SLIDER_NONE = 0,
} slider_id_t;

typedef enum {
	GYROSCOPE_NONE = 0,
} gyroscop_id_t;

// ============== peripherals ===================

typedef enum audio_e {
	AUDIO_NONE = 0,
	AUDIO_OSS,
	AUDIO_ALSA = 4
} audio_id_t;

typedef enum {
	USB_NONE = 0,
	USB_INTERNAL = 3 //using testscript
} usb_id_t;

typedef enum {
	FRONTLIGHT_NONE = 0,
	FRONTLIGHT_PWM,
} frontlight_id_t;

typedef enum {
	LIGHTSENSOR_NONE = 0,
} lightsensor_id_t;

// =============== communications =============

typedef enum {
	BLUETOOTH_NONE = 0,
} bluetooth_id_t;

typedef enum {
	WIFI_NONE = 0,
	WIFI_RTL8188EU = 8,
	WIFI_RTL8189FS = 11,
} wifi_id_t;

typedef enum {
	GSM_NONE = 0,
} gsm_id_t;

//========================
bool init_hwconfig(void);

device_id_t device_ID(void); //index
platform_id_t device_platform(void);
unsigned int device_number(void);

display_id_t device_display(void);
unsigned int device_display_height(void);
unsigned int device_display_width(void);
unsigned int device_display_scanline(void);
unsigned int device_display_dpi(void);
uint8_t device_display_position(void);

epdc_id_t device_epdc(void);

keyboard_id_t device_keyboard(void);

touchpanel_id_t device_touchpanel(void);
bool device_has_touchpanel(void);

slider_id_t device_slider(void);
bool device_has_slider(void);

gyroscop_id_t device_gyroscope(void);
bool device_has_gyroscope(void);

audio_id_t device_audio(void);
bool device_has_audio(void);

bool device_has_extcard(void);

usb_id_t device_usb(void);
bool device_has_usb(void);
bool device_has_usbhost(void);

frontlight_id_t device_frontlight(void);
bool device_has_frontlight(void);

lightsensor_id_t device_lightsensor(void);
bool device_has_lightsensor(void);

bluetooth_id_t device_bluetooth(void);
bool device_has_bluetooth(void);

wifi_id_t device_wifi(void);
bool device_has_wifi(void);

gsm_id_t device_gsm(void);
bool device_has_gsm(void);


//typedef struct {
//
//	// global parameters
//
//	int device_id;                    /* numeric ID for each device */
//	platform_t platform_id;
//	keyboard_t keyboard_id;
//	int touch_id;
//	int epdc_id;
//	int audio_id;
//	int frontlight_id;
//	int lightsensor_id;
//	int wifi_id;
//	int bluetooth_id;
//
//	int display_diagonal;             /* 50, 60, 80, 133 ... */
//	int display_width;                /* w,h,scanline are adjusted when orientation changed */
//	int display_height;
//	int display_scanline;
//
//	char *device_name;                /* device name (like "PB624")  */
//	char *serial;                     /* device serial number */
//	char *waveform_name;              /* name of the waveform */
//
//	// flash and sdcard partitions
//
//	char *flash_device;
//	char *flash_user;
//	char *flash_secure;
//	char *sdcard_device;
//	char *sdcard_part1;
//
//	// mount points
//
//	char *mnt_flash;
//	char *mnt_sdcard;
//	char *mnt_usb;
//	char *mnt_secure;
//
//	// eink
//
//	void     (*eink_set_orientation)(int o);
//	int      (*eink_get_orientation)();
//	void *   (*eink_get_framebuffer)();         /*get framebuffer mmapped address */
//	uint32_t (*eink_supported_waveforms)();     /* get mask of supportes wf's */
//	void     (*eink_update)(uint32_t type, int x, int y, int w, int h);
//	bool     (*eink_is_updating)();
//	void     (*eink_wait_complete)();
//
//	// frontlight
//
//	void     (*frontlight_on)(bool state);
//	void     (*frontlight_setvalue)(int value);
//	int      (*frontlight_getvalue)();
//	void     (*frontlight_save)();
//
//	// lightsensor
//
//	int      (*lightsensor_read)();
//	bool     (*lightsensor_auto_supported)();
//	void     (*lightsensor_set_auto)(bool flag);
//	bool     (*lightsensor_get_auto)();
//
//	// battery and charger
//
//	int      (*battery_voltage)();
//	int      (*battery_percent)();
//	int      (*battery_status)();             /* battery_status_t */
//	int      (*charge_status)();              /* charge_status_t */
//
//	// power management
//
//	int      (*suspend)(int msec, int mode);  /* mode: suspend_mode_t */
//	int      (*suspend_lock)(int msec);
//	bool     (*suspend_is_locked)();
//
//	// usb
//
//	int      (*usb_status)();                 /* usb_status_t */
//
//	// sd card
//
//	bool     (*sd_inserted)();
//
//	// boot logo
//
//	void     (*logo_set_permanent)();   /* main logo */
//	void     (*logo_set_temporary)();   /* current page */
//	void     (*logo_restore)();         /* restore permanent logo */
//
//	// buttons
//
//	uint32_t (*buttons_available)();    /* mask for buttons present on device */
//	uint32_t (*buttons_pressed)();      /* mask for currently hold buttons */
//
//	// touch panel
//
//	void     (*touch_transform)(int *x, int *y); /* transform values from event to screen coordinates */
//	int      (*touch_deadzone)();                /* touch drag deadzone */
//
//	// swupdate
//
//	bool     (*set_update_flag)();      /* switch to cramfs */
//
//} hw_device_data;

#endif /* SRC_HWCONFIG_H_ */

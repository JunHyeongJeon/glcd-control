/*
 * st7565.h

 *
 *  Created on: Jun 30, 2015
 *      Author: Jun
 */

#ifndef ST7565_H_
#define ST7565_H_

#include <stdint.h>
#include "gpio_drv.h"
#include "siu_init.h"
#include "common.h"
#include "pin_config.h"

#define BLACK 1
#define WHITE 0

#define LCDWIDTH 128
#define LCDHEIGHT 64

#define CMD_DISPLAY_OFF   0xAE
#define CMD_DISPLAY_ON    0xAF

#define CMD_SET_DISP_START_LINE  0x40
#define CMD_SET_PAGE  0xB0

#define CMD_SET_COLUMN_UPPER  0x10
#define CMD_SET_COLUMN_LOWER  0x00

#define CMD_SET_ADC_NORMAL  0xA0
#define CMD_SET_ADC_REVERSE 0xA1

#define CMD_SET_DISP_NORMAL 0xA6
#define CMD_SET_DISP_REVERSE 0xA7

#define CMD_SET_ALLPTS_NORMAL 0xA4
#define CMD_SET_ALLPTS_ON  0xA5
#define CMD_SET_BIAS_9 0xA2 
#define CMD_SET_BIAS_7 0xA3

#define CMD_RMW  0xE0
#define CMD_RMW_CLEAR 0xEE
#define CMD_INTERNAL_RESET  0xE2
#define CMD_SET_COM_NORMAL  0xC0
#define CMD_SET_COM_REVERSE  0xC8
#define CMD_SET_POWER_CONTROL  0x28
#define CMD_SET_RESISTOR_RATIO  0x20
#define CMD_SET_VOLUME_FIRST  0x81
#define  CMD_SET_VOLUME_SECOND  0
#define CMD_SET_STATIC_OFF  0xAC
#define  CMD_SET_STATIC_ON  0xAD
#define CMD_SET_STATIC_REG  0x0
#define CMD_SET_BOOSTER_FIRST  0xF8
#define CMD_SET_BOOSTER_234  0
#define  CMD_SET_BOOSTER_5  1
#define  CMD_SET_BOOSTER_6  3
#define CMD_NOP  0xE3
#define CMD_TEST  0xF0


#define OUTPUT 0x0201
#define HIGH 1
#define LOW 0



void glcd_begin(uint8_t contrast);
void spiwrite(uint8_t c);

void st7565_init(void);

void st7565_command(uint8_t c);
void st7565_data(uint8_t c);

void st7565_set_brightness(uint8_t val);


void glcd_clear_screen(void);
void clear_buffer(uint8_t *);

void write_buffer(uint8_t *buffer);

void testdrawbitmap(uint8_t *buff, const uint8_t *bitmap, uint8_t w, uint8_t h);

void glcd_display(void);

void updateBoundingBox(uint8_t xmin, uint8_t ymin, uint8_t xmax, uint8_t ymax);

void setpixel(uint8_t x, uint8_t y, uint8_t color);

#endif /* ST7565_H_ */

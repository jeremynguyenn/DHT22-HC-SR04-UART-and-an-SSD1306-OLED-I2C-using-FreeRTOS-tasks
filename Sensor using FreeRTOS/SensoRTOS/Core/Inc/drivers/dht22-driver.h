/*
 * dht22-driver.h
 *
 *  Created on: May 3, 2025
 *      Author: sande
 */

#ifndef INC_DRIVERS_DHT22_DRIVER_H_
#define INC_DRIVERS_DHT22_DRIVER_H_

#include <stdint.h>

void DHT22_Init(void);
uint8_t DHT22_Read(uint8_t* temp, uint8_t* humidity);

#endif /* INC_DRIVERS_DHT22_DRIVER_H_ */

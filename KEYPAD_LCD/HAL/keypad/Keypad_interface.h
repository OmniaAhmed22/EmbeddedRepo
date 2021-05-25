//*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */ 
/*****************************************************************************/

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

void HAL_Keypad_voidInit(void);

void HAL_Keypad_voidGetPressedKey(uint8_t *ptr_PressedValue);

#endif /* KEYPAD_INTERFACE_H_ */


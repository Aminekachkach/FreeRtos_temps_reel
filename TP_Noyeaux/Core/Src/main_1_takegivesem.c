///* USER CODE BEGIN Header */
///**
// ******************************************************************************
// * @file           : main.c
// * @brief          : Main program body
// ******************************************************************************
// * @attention
// *
// * Copyright (c) 2023 STMicroelectronics.
// * All rights reserved.
// *
// * This software is licensed under terms that can be found in the LICENSE file
// * in the root directory of this software component.
// * If no LICENSE file comes with this software, it is provided AS-IS.
// *
// ******************************************************************************
// */
///* USER CODE END Header */
///* Includes ------------------------------------------------------------------*/
//#include "main.h"
//#include "cmsis_os.h"
//#include "usart.h"
//#include "gpio.h"
//
///* Private includes ----------------------------------------------------------*/
///* USER CODE BEGIN Includes */
//
///* USER CODE END Includes */
//
///* Private typedef -----------------------------------------------------------*/
///* USER CODE BEGIN PTD */
//#define STACK_SIZE 1000
//
///* USER CODE END PTD */
//
///* Private define ------------------------------------------------------------*/
///* USER CODE BEGIN PD */
//
//SemaphoreHandle_t sem1;
///* USER CODE END PD */
//
///* Private macro -------------------------------------------------------------*/
///* USER CODE BEGIN PM */
//
///* USER CODE END PM */
//
///* Private variables ---------------------------------------------------------*/
//
///* USER CODE BEGIN PV */
//
///* USER CODE END PV */
//
///* Private function prototypes -----------------------------------------------*/
//void SystemClock_Config(void);
//void MX_FREERTOS_Init(void);
///* USER CODE BEGIN PFP */
//
///* USER CODE END PFP */
//
///* Private user code ---------------------------------------------------------*/
///* USER CODE BEGIN 0 */
//// TODO écrire le code de la tache
////void codeTache (void * pvParameters) {
////	int compteur = 0;
////	int pin_value;
////	int duree = portTICK_PERIOD_MS;
////	char* s = pcTaskGetName(xTaskGetCurrentTaskHandle());
////	while (1) {
////		HAL_GPIO_TogglePin(GPIOI, LED_Pin);
////		int pin_value = HAL_GPIO_ReadPin(GPIOI, LED_Pin);
////		printf("La Led est a l'etat %d et je m'endors pour %d periodes\n\r", pin_value, duree);
////		vTaskDelay(duree);
////		compteur++;
////	}
////}
////
//
//void taskGive(void *p){
//
//	for(;;){
//		printf("Avant sem Give \r\n");
//		if (xSemaphoreGive(sem1) == pdTRUE){
//			printf("Apres sem Give \r\n");
//		}
//		else {
//			NVIC_SystemReset();
//		}
//		vTaskDelay(1000);
//	}
//
//}
//
//void taskTake(void *p){
//	for(;;){
//		printf("avant sem prendre \r\n");
//		if(xSemaphoreTake(sem1, portMAX_DELAY) == pdTRUE){
//			printf("apres sem prendre \r\n");
//
//		}
//		else{
//			NVIC_SystemReset();
//		}
//	}
//}
//
///* USER CODE END 0 */
//
///**
// * @brief  The application entry point.
// * @retval int
// */
//int __io_putchar(int ch) {
//	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
//	return ch;
//}
//int main(void)
//{
//	/* USER CODE BEGIN 1 */
//	BaseType_t xReturned;
//	TaskHandle_t xHandle1 = NULL;
//
//	/* USER CODE END 1 */
//
//	/* MCU Configuration--------------------------------------------------------*/
//
//	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
//	HAL_Init();
//
//	/* USER CODE BEGIN Init */
//
//	/* USER CODE END Init */
//
//	/* Configure the system clock */
//	SystemClock_Config();
//
//	/* USER CODE BEGIN SysInit */
//
//	/* USER CODE END SysInit */
//
//	/* Initialize all configured peripherals */
//	MX_GPIO_Init();
//	MX_USART1_UART_Init();
//	/* USER CODE BEGIN 2 */
//	// TODO créer la tâche
//	sem1 = xSemaphoreCreateBinary();
////	xReturned = xTaskCreate(
////		codeTache, /* Function that implements the task. */
////		"Task1", /* Text name for the task. */
////		STACK_SIZE, /* Stack size in words, not bytes. */
////		(void *) DELAY_1, /* Parameter passed into the task. */
////		tskIDLE_PRIORITY,/* Priority at which the task is created. */
////		&xHandle1 ); /* Used to pass out the created task's handle. */
//
//	xReturned = xTaskCreate(
//			taskGive, /* Function that implements the task. */
//			"Task1", /* Text name for the task. */
//			STACK_SIZE, /* Stack size in words, not bytes. */
//			NULL, /* Parameter passed into the task. */
//			tskIDLE_PRIORITY+2,/* Priority at which the task is created. */
//			&xHandle1 ); /* Used to pass out the created task's handle. */
//
//	xReturned = xTaskCreate(
//			taskTake, /* Function that implements the task. */
//			"Task2", /* Text name for the task. */
//			STACK_SIZE, /* Stack size in words, not bytes. */
//			NULL, /* Parameter passed into the task. */
//			tskIDLE_PRIORITY+1,/* Priority at which the task is created. */
//			&xHandle1 ); /* Used to pass out the created task's handle. */
//
//	vTaskStartScheduler();
//	/* USER CODE END 2 */
//
//	/* Call init function for freertos objects (in freertos.c) */
//	MX_FREERTOS_Init();
//
//	/* Start scheduler */
//	osKernelStart();
//
//	/* We should never get here as control is now taken by the scheduler */
//	/* Infinite loop */
//	/* USER CODE BEGIN WHILE */
//	while (1)
//	{
//		/* USER CODE END WHILE */
//
//		/* USER CODE BEGIN 3 */
//	}
//	/* USER CODE END 3 */
//}
//
///**
// * @brief System Clock Configuration
// * @retval None
// */
//void SystemClock_Config(void)
//{
//	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
//	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
//
//	/** Configure the main internal regulator output voltage
//	 */
//	__HAL_RCC_PWR_CLK_ENABLE();
//	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
//
//	/** Initializes the RCC Oscillators according to the specified parameters
//	 * in the RCC_OscInitTypeDef structure.
//	 */
//	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
//	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
//	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
//	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
//	RCC_OscInitStruct.PLL.PLLM = 25;
//	RCC_OscInitStruct.PLL.PLLN = 432;
//	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
//	RCC_OscInitStruct.PLL.PLLQ = 2;
//	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
//	{
//		Error_Handler();
//	}
//
//	/** Activate the Over-Drive mode
//	 */
//	if (HAL_PWREx_EnableOverDrive() != HAL_OK)
//	{
//		Error_Handler();
//	}
//
//	/** Initializes the CPU, AHB and APB buses clocks
//	 */
//	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
//			|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
//	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
//	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
//	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
//	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
//
//	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
//	{
//		Error_Handler();
//	}
//}
//
///* USER CODE BEGIN 4 */
//
///* USER CODE END 4 */
//
///**
// * @brief  Period elapsed callback in non blocking mode
// * @note   This function is called  when TIM6 interrupt took place, inside
// * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
// * a global variable "uwTick" used as application time base.
// * @param  htim : TIM handle
// * @retval None
// */
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
//{
//	/* USER CODE BEGIN Callback 0 */
//
//	/* USER CODE END Callback 0 */
//	if (htim->Instance == TIM6) {
//		HAL_IncTick();
//	}
//	/* USER CODE BEGIN Callback 1 */
//
//	/* USER CODE END Callback 1 */
//}
//
///**
// * @brief  This function is executed in case of error occurrence.
// * @retval None
// */
//void Error_Handler(void)
//{
//	/* USER CODE BEGIN Error_Handler_Debug */
//	/* User can add his own implementation to report the HAL error return state */
//	__disable_irq();
//	while (1)
//	{
//	}
//	/* USER CODE END Error_Handler_Debug */
//}
//
//#ifdef  USE_FULL_ASSERT
///**
// * @brief  Reports the name of the source file and the source line number
// *         where the assert_param error has occurred.
// * @param  file: pointer to the source file name
// * @param  line: assert_param error line source number
// * @retval None
// */
//void assert_failed(uint8_t *file, uint32_t line)
//{
//	/* USER CODE BEGIN 6 */
//	/* User can add his own implementation to report the file name and line number,
//     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
//	/* USER CODE END 6 */
//}
//#endif /* USE_FULL_ASSERT */
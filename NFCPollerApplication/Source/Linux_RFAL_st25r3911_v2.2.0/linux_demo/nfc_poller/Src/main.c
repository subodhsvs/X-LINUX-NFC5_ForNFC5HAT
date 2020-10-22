/******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2019 STMicroelectronics</center></h2>
  *
  * Licensed under ST MYLIBERTY SOFTWARE LICENSE AGREEMENT (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/myliberty
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied,
  * AND SPECIFICALLY DISCLAIMING THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
******************************************************************************/

/*
 ******************************************************************************
 * INCLUDES
 ******************************************************************************
 */
#include <stdio.h>
#include "platform.h"
#include "st_errno.h"
#include "rfal_analogConfig.h"
#include "rfal_nfca.h"
#include "example_poller.h"
/*
 ******************************************************************************
 * DEFINES
 ******************************************************************************
 */
#define logUsart	printf

/*
 ******************************************************************************
 * MAIN FUNCTION
 ******************************************************************************
 */
int main(void)
{
	//logUsart("Welcome to the ST25R3916 NFC Poller Demo on Linux..\n");
	//set terminal to line buffer so as to update charecter by charecter
	setlinebuf(stdout);
	int ret = 0;

	/* Initialize the platform */
	/* Initialize GPIO */
  	ret = gpio_init();
	if(ret != ERR_NONE)
		goto error;


	/* Initialize SPI */
	ret = spi_init();
	if(ret != ERR_NONE)
		goto error;

	/* Initialize interrupt mechanism */
	ret = interrupt_init();
	if (ret != ERR_NONE)
		goto error;

	/* Initialize rfal and run example code for NFC */
	exampleRfalPollerRun();

error:
	return ret;
}

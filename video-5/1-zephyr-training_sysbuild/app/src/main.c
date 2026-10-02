
/**
 * @file      main.c
 * @brief     Main entry point
 *
 * Copyright (C) Witekio
 *
 * This file is part of Witekio Zephyr Training.
 *
 * This demonstration is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This demonstration is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with This demonstration. If not, see <http://www.gnu.org/licenses/>.
 */

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(zephyr_training, LOG_LEVEL_INF);

/**
 * @brief Main function
 * @return Always returns 0
 */
int
main(void) {

    LOG_INF("Hello world! %s", CONFIG_BOARD_TARGET);

    return 0;
}


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

#include <psa/crypto.h>
#include <psa/internal_trusted_storage.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(zephyr_training, LOG_LEVEL_INF);

/**
 * @brief Main function
 * @return Always returns 0
 */
int
main(void) {

    LOG_INF("Hello world! %s", CONFIG_BOARD_TARGET);

    psa_status_t status;
    uint32_t random;
    status = psa_generate_random((uint8_t*)&random, sizeof(random));
    if (PSA_SUCCESS != status) {
        LOG_ERR("Unable to generate random number");
    } else {
        LOG_INF("Random number: %u", random);
    }

    uint32_t boot_count = 0;
    psa_storage_uid_t uid = 1;
    size_t size = 0;
    status = psa_its_get(uid, 0, sizeof(boot_count), &boot_count, &size);
    if (PSA_SUCCESS != status && PSA_ERROR_DOES_NOT_EXIST != status) {
        LOG_ERR("Unable to read boot count");
    }

    boot_count++;
    status = psa_its_set(uid, sizeof(boot_count), &boot_count, PSA_STORAGE_FLAG_NONE);
    if (PSA_SUCCESS != status) {
        LOG_ERR("Unable to write boot count");
    }

    LOG_INF("Boot count: %u", boot_count);

    return 0;
}

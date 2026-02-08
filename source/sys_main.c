/* Example main showing how to use the io_driver API
 * Edit the direction of I/O pins by changing the macros in
 * source/io_driver.h (GIOA5_IS_OUTPUT, GIOA6_IS_OUTPUT, etc.).
 */

#include "sys_common.h"
#include "io_driver.h"

int main(void)
{

    /* initialize logical I/O mapping and directions */
    ecu_io_init();

    /* Example usage:
     * - Read logical input ECU_INPUT_1 (GIOA0)
     * - Drive ECU_OUTPUT_1 (GIOB3) to the same level
     * - Toggle ECU_OUTPUT_2 periodically
     */
    uint32_t delay = 0U;

    while (1)
    {
        bool in1 = ecu_io_read_input(ECU_INPUT_1);
        ecu_io_write_output(ECU_OUTPUT_3, in1);

        /* simple software delay/counter to toggle another output */
        if (++delay > 1000000U)
        {
            ecu_io_toggle_output(ECU_OUTPUT_2);
            delay = 0U;
        }

    }

    return 0;
}

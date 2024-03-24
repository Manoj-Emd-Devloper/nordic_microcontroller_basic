#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/sys/printk.h>

int main(void)
{
        const struct device *uart = DEVICE_DT_GET(DT_NODELABEL(uart0));

        if (!device_is_ready(uart))
        {
                return;
        }

        int err = uart_configure(uart, &uart_cfg);

	if (err == -ENOSYS) {
		return -ENOSYS;
	}
        
        return 0;
}

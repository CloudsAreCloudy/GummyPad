print("Starting...")

import board
import busio

from kmk.kmk_keyboard import KMKKeyboard
from kmk.keys import KC
from kmk.scanners import DiodeOrientation
from kmk.extensions.display import Display, TextEntry, ImageEntry
from kmk.extensions.display.ssd1306 import SSD1306
from kmk.extensions.RGB import RGB
from kmk.modules.layers import Layers
from kmk.modules.encoder import EncoderHandler

encoder_handler = EncoderHandler()
keyboard = KMKKeyboard()
layers = Layers()
i2c_bus = busio.I2C(board.GP9, board.GP8)
keyboard.modules = [layers, encoder_handler]
rgb = RGB(pixel_pin=board.GP10, num_pixels=9)


# Keyboard column and row configuration
keyboard.col_pins = (board.GP21, board.GP20, board.GP0)
keyboard.row_pins = (board.GP3, board.GP7, board.GP5, board.GP6)
keyboard.diode_orientation = DiodeOrientation.COL2ROW

# Rotary Encoder Configuration
encoder_handler.pins = (
    (board.GP4, board.GP2, board.GP1),
    )

encoder_handler.map = [ ((KC.VOLD, KC.VOLU, KC.MUTE),),
                        ]

# Display Configuration

driver = SSD1306(
    i2c=i2c_bus,
    device_address=0x3C,
    )

display = Display(
    display=driver,
    width=128,
    height=64,
    brightness=1,
    brightness_step=0.01,
    dim_time=25,
    dim_target=0.1,
    off_time=60,
    )
    

display.entries = [
    TextEntry(text="Hey Cloudy!", x=0, y=0)
    ]


keyboard.keymap = [
    [KC.A, KC.B, KC.C, KC.D, KC.E, KC.F, KC.G, KC.H, KC.I, KC.J, KC.K, KC.L] # Layer 1
    ]

if __name__ == '__main__':
    keyboard.extensions.append(display)
    keyboard.extensions.append(rgb)
    keyboard.go()

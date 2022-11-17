from cis400 import *



def clicked(mx, my):
    global x, y, drawn
    drawn = True
    x = mx
    y = my

def draw_frame():
    global first_time, old_x, old_y, x, y
    global first_click, second_time
    global pressed_R, pressed_G, pressed_B
    if first_time is True:
        set_clear_color(0.0, 0.0, 0.0)
        clear()
        set_stroke_width(2)
        first_time = False
        old_x = x
        old_y = y



    if pressed_R == True:
        set_stroke_color(1.0, 0, 0)
    elif pressed_B == True:
        set_stroke_color(0, 0, 1.0)
    else:
        set_stroke_color(0, 1.0, 0)

    if drawn:
        if first_click is True:
            old_x = x
            old_y = y
            first_click = False

        if second_time is True:
            old_x = x
            old_y = y
            second_time = False

        draw_line(old_x, old_y, x, y)
        old_x = x
        old_y = y

def keydown(key):
    global pressed_R, pressed_G, pressed_B
    global second_time, first_click, drawn

    if key == "r":
        pressed_R = True
        pressed_G = False
        pressed_B = False
        first_click = True
        second_time = True
        drawn = False
    elif key == "b":
        pressed_B = True
        pressed_R = False
        pressed_G = False
        first_click = True
        second_time = True
        drawn = False
    elif key == "g":
        pressed_G = True
        pressed_R = False
        pressed_B = False
        first_click = True
        second_time = True
        drawn = False

old_x = 0
old_y = 0
x = 0
y = 0
drawn = False
first_time = True
first_click = True
pressed_R = False
pressed_G = True
pressed_B = False
second_time = False

start_graphics(draw_frame, 2400, mouse_press=clicked, key_press=keydown)

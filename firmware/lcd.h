#ifndef LCD_HEADER_H
#define LCD_HEADER_H

// Modes for lcd_send_byte
#define LCD_CHARACTER  1
#define LCD_COMMAND    0

#define MAX_LINES      2
#define MAX_CHARS      16

void lcd_clear(void);
void lcd_set_cursor(int line, int position);
void lcd_string(const char *s);
void lcd_init();
void lcd_write_line(int line, char *message);

#endif
// 控件

#include <stdio.h>
#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    // 窗口    
    GtkWidget *window;
    // 按钮
    GtkWidget *button;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(window, 800, 800);
    // 创建按钮
    button = gtk_button_new_with_label("Hello World");
    // 添加按钮到window
    gtk_container_add((GtkContainer *)window, button);
    // 获取按钮的内容
    const char *result = gtk_button_get_label((GtkButton *)button);
    printf("result = %s\n", result);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

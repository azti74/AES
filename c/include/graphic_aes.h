typedef unsigned char byte;
void graphicAes(int argc, char **argv);
char entree[100] = "";
char sortie[100] = "";
byte key[65] = "";

struct Widgets {
  GtkWidget *p_vte;
  GtkWidget *p_button_open;
  GtkWidget *p_label_open;
  GtkWidget *p_window;
  GtkWidget *p_main_box_vertical;
  GtkWidget *p_main_box_horizontal;
  GtkWidget *p_left_box;
  GtkWidget *p_right_box;
  GtkWidget *p_button ;
  GtkWidget *p_button_encode;
  GtkWidget *p_button_decode;
  GtkWidget *p_label_choix;
  GtkWidget *p_label_cle;
  GtkWidget *p_text;
  GtkWidget *p_button_save;
  GtkWidget *p_label_save;
  GtkWidget* p_radio_btn_cbc;
  GtkWidget* p_radio_btn_ebc;
  GtkWidget *p_case_bmp;
  GtkWidget *p_radio_btn_aes_128;
  GtkWidget *p_radio_btn_aes_192;
  GtkWidget *p_radio_btn_aes_256;
  GtkWidget *p_case_hexa;
};
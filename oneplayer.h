#ifndef ONEPLAYER_H
#define ONEPLAYER_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMessageBox>
#include <QFile>

#include <math.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "elemento.h"
#include "grafica.h"
#include "muros.h"
#include "niveles.h"
#include "mago.h"
#include "minotauro.h"
#include "jefe_uno.h"
#include "disparo_m.h"
#include "disparo_c.h"
#include "dis_jefe_1.h"
#include "dis_jefe_2.h"

namespace Ui {
class oneplayer;
}

class oneplayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit oneplayer(QWidget *parent = nullptr);
    ~oneplayer();
    int h_limit,w_limit;
    string dato, x_pix, y_pix, x_tam, y_tam,num;
    int numero_x,numero_y, largo;
    int cantidad_x, cantidad_y;
    float distancia = 0, dificultad = 1;
    int vida_one  = 100;//vida del jugador
    int puntuacion_one  = 0;//puntuacion del jugador
    int vida_j  = 1000;//vida del jefe
    int estado = 0, est_mago = 0, con_cad = 0, disparo_jefe = 0;
    bool eliminar = false;//eliminar disparos
    void nivel(string num_);// trbajo del nivel
    QList<muros*> contras;//creacion de muros
public slots:
    void actualizar();
private slots:
    void on_actionVolver_triggered();
    void on_actionReiniciar_triggered();
    void on_actionPausa_triggered();
    void on_actionComo_Jugar_triggered();

    void on_actionCargar_partida_triggered();

    void on_actionGuardar_partida_triggered();

private:
    Ui::oneplayer *ui;
    oneplayer *one;
    bool conti = true;//continuardor del juego
    int enemigo = 1, tipo_dis= 0;//definidor de enmigos
    QTimer *timer;
    QGraphicsScene *scene;
    //_________personajes_______
    //listas de disparos
    QList<disparo_c*> discab;
    QList<disparo_m*> dismag;
    QList<dis_jefe_1*> dis_j1;
    QList<dis_jefe_2*> dis_j2;
    //cracion de personajes
    jefe_uno *jefe;
    grafica *jug;
    QList<mago*> magos;
    QList<minotauro*> tauros;
    void borderCollision(elemento *b);
    void keyPressEvent(QKeyEvent *event);
};

#endif // ONEPLAYER_H

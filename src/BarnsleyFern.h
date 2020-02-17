#pragma once
#include "Fractal.h"

/**
 * @class   [BarnsleyFern]
 * @brief                       klasa reprezentujaca paproc Barnsleya - dziedziczy po klasie Fractal 
 */
class BarnsleyFern : public Fractal {
public:

	/**
     * @fn      [BarnsleyFern]
     * @brief                       konstruktor, ktory alokuje pamiec na wszystkie punkty fraktala, inicjalizuje rozmiary okna
     *                              \ oraz ustawia poczatkowy kolor punktow,  
     * @param   [const float]       XWINDOW - szerokosc okna,
     * @param   [const float]       YWINDOW - wysokosc okna.
     */
	BarnsleyFern(const float XWINDOW , const float YWINDOW );


	/**
     * @fn      [CalculatePoints]   
     * @brief                       wirtualna metoda override, ktora przelicza punkty fraktala na podstawie 
     *                              \ wylosowanego prawdopodobienstwa - wola ona metode @CalculatePoints oraz @MapAllPoints.
     */
	void CalculatePoints()override;


	/**
     * @fn      [CalcProbability] 
     * @brief                       czysto wirtualna metoda override, ktora wylicza prawdopodobienstwo, na podstawie ktorego
     *                              \ wolana jest odpowiednia metoda skladowa klasy przypisujaca wspolrzedne punktu do tablicy.
     */
	void CalcProbability()override;


	/**
     * @fn      [MapPointX]         
     * @brief                       czysto wirtualna metoda override, ktora mapuje wspolrzedna x punktu fraktala,
     * @param   [float]             x - wspolrzedna x punktu,
     * @return  [float]             odpowiednio zmapowana nowa wspolrzedna x.
     */
	float Map_pointX(float& x)override;


	/**
     * @fn      [MapPointY]         
     * @brief                       czysto wirtualna metoda override, ktora mapuje wspolrzedna y punktu fraktala,
     * @param   [float]             y - wspolrzedna y punktu,
     * @return  [float]             odpowiednio zmapowana nowa wspolrzedna y.
     */
	float Map_pointY(float& y)override;


	/**
     * @fn      [Func_1-4]        
     * @brief                       zestaw metod, na podstawie ktorych przeliczane sa punkty w specyficzny dla danej metody sposob,
     * 
     * @param   [int]               iter - numer obecnej iteracji, a takze indeks dla danej pary punktow.
     */
	void Func_1(int iteration);
	void Func_2(int iteration);
	void Func_3(int iteration);
	void Func_4(int iteration);

};


BarnsleyFern::BarnsleyFern(const float XWINDOW, const float YWINDOW) : Fractal(XWINDOW,YWINDOW){
	CalculatePoints();
	MapAllPoints();
}

void BarnsleyFern::CalcProbability() {
	m_probability = rand() % 100 + 1;
}

void BarnsleyFern::Func_1(int iteration) {
	m_xy[iteration].first = 0.0f * m_xy[iteration - 1].first + 0.0f * m_xy[iteration - 1].second;
	m_xy[iteration].second = 0.0f * m_xy[iteration - 1].first + 0.16f * m_xy[iteration - 1].second;
}

void BarnsleyFern::Func_2(int iteration) {
	m_xy[iteration].first = 0.85f * m_xy[iteration - 1].first + 0.04f * m_xy[iteration - 1].second;
	m_xy[iteration].second = -0.04f * m_xy[iteration - 1].first + 0.85f * m_xy[iteration - 1].second + 1.2f;
}

void BarnsleyFern::Func_3(int iteration) {
	m_xy[iteration].first = 0.20f * m_xy[iteration - 1].first + -0.26f  * m_xy[iteration - 1].second;
	m_xy[iteration].second = 0.23f * m_xy[iteration - 1].first + 0.22f  * m_xy[iteration - 1].second + 1.6f;
}

void BarnsleyFern::Func_4(int iteration) {
	m_xy[iteration].first = -0.15f * m_xy[iteration - 1].first + 0.28f   * m_xy[iteration - 1].second;
	m_xy[iteration].second = 0.26f * m_xy[iteration - 1].first + 0.24f * m_xy[iteration - 1].second + 0.44f;
}

void BarnsleyFern::CalculatePoints() {
	srand(time(NULL));
	
	for (int i = 1; i <ITERATION_MAX; ++i) {
		
		CalcProbability();

		if (0 < m_probability && m_probability <= 1) {
			Func_1(i);
		}
		else if (1 < m_probability && m_probability <= 86) {
			Func_2(i);
		}
		else if (86 < m_probability && m_probability <= 93) {
			Func_3(i);
		}
		else if (93 < m_probability && m_probability <= 100) {
			Func_4(i);
		}

	}
}

float BarnsleyFern::Map_pointX(float& x) {
	return (x * m_xwindow * 0.25f + m_xwindow / 2.0f - 20.0f);
	
}

float BarnsleyFern::Map_pointY(float& y) {
	return (y * 0.25f * m_ywindow / 2.0f + 20.f);
	
}
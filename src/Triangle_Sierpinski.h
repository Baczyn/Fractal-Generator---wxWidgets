#pragma once
#include "Fractal.h"

/**
 * @class   [SierpinskiTriangle]
 * @brief                       klasa reprezentujaca trojkat Sierpinskiego - dziedziczy po klasie Fractal 
 */
class SierpinskiTriangle: public Fractal{
public:
	
	/**
     * @fn      [SierpinskiTriangle]
     * @brief                       konstruktor, ktory alokuje pamiec na wszystkie punkty fraktala, inicjalizuje rozmiary okna
     *                              \ oraz ustawia poczatkowy kolor punktow,  
     * @param   [const float]       XWINDOW - szerokosc okna,
     * @param   [const float]       YWINDOW - wysokosc okna.
     */
	SierpinskiTriangle(const float XWINDOW, const float YWINDOW);


	/**
     * @fn      [CalculatePoints]   
     * @brief                       wirtualna metoda override, ktora przelicza punkty fraktala na podstawie 
     *                              \ wylosowanego prawdopodobienstwa - wola ona metode @CalculatePoints oraz @MapAllPoints.
     */
	void CalculatePoints();


	/**
     * @fn      [CalcProbability] 
     * @brief                       czysto wirtualna metoda override, ktora wylicza prawdopodobienstwo, na podstawie ktorego
     *                              \ wolana jest odpowiednia metoda skladowa klasy przypisujaca wspolrzedne punktu do tablicy.
     */
	void CalcProbability();


	/**
     * @fn      [Map_pointX]         
     * @brief                       czysto wirtualna metoda, ktora mapuje wspolrzedna x punktu fraktala,
     * @param   [float&]            x - wspolrzedna x punktu,
     * @return  [float]             odpowiednio zmapowana nowa wspolrzedna x.
     */
	float Map_pointX(float& x)override;


	/**
     * @fn      [Map_pointY]         
     * @brief                       czysto wirtualna metoda, ktora mapuje wspolrzedna y punktu fraktala,
     * @param   [float&]            y - wspolrzedna y punktu,
     * @return  [float]             odpowiednio zmapowana nowa wspolrzedna y.
     */
	float Map_pointY(float& y)override;


	/**
     * @fn      [Func_1-3]        
     * @brief                       zestaw metod, na podstawie ktorych przeliczane sa punkty w specyficzny dla danej metody sposob,
     * 
     * @param   [int]               iter - numer obecnej iteracji, a takze indeks dla danej pary punktow.
     */
	void Func_1(int iter);
	void Func_2(int iter);
	void Func_3(int iter);

};


SierpinskiTriangle::SierpinskiTriangle(const float XWINDOW, const float YWINDOW) 
:Fractal(XWINDOW,YWINDOW)
{
	CalculatePoints();
	MapAllPoints();
}


void SierpinskiTriangle::CalcProbability() {
	m_probability = rand() % 3 + 1;
}

void SierpinskiTriangle::Func_1(int iteration) {
	m_xy[iteration].first = (m_xy[iteration - 1].first) / 2.0f;
	m_xy[iteration].second = (m_xy[iteration - 1].second) / 2.0f;
}


void SierpinskiTriangle::Func_2(int iteration) {
	m_xy[iteration].first = ((m_xy[iteration - 1].first) / 2.0f) + 0.5f;
	m_xy[iteration].second = (m_xy[iteration - 1].second) / 2.0f;
}


void SierpinskiTriangle::Func_3(int iteration) {
	m_xy[iteration].first = ((m_xy[iteration - 1].first) / 2.0f) + 0.25f;
	m_xy[iteration].second = (m_xy[iteration - 1].second) / 2.0f + (sqrt(3.0f) / 2.0f);
}


void SierpinskiTriangle::CalculatePoints() {
	srand(time(NULL));
	
	for (int i = 1; i < ITERATION_MAX; ++i) {
		CalcProbability();
		if (m_probability == 1)
			Func_1(i);
		else if (m_probability == 2)
			Func_2(i);
		else if (m_probability == 3)
			Func_3(i);
	}
}


float SierpinskiTriangle::Map_pointX(float& x) {
	return x * m_xwindow * 0.9f + m_xwindow / 13.0f;
}

float SierpinskiTriangle::Map_pointY(float& y) {
	return  (y * 1.1f * m_ywindow / 2.0f + 20.f);

}
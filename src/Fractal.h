#pragma once
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>


long int ITERATION_MAX = 30000; /* liczba iteracji - punktow z ktorych sklada sie kazdy fraktal
                                 - im wiecej tym dokladniejszy fraktal, lecz tym wolniej dziala caly program */


/**
 * @class       [Fractal]
 * @brief                           wirtualna klasa - udostepnia interfejs kazdemu fraktalowi, ktory dziedziczy po tej klasie.
 */
class Fractal {
public:

	friend class GUI;


	/**
     * @fn      [Fractal]
     * @brief                       konstruktor, ktory alokuje pamiec na wszystkie punkty fraktala, inicjalizuje rozmiary okna
     *                              \ oraz ustawia poczatkowy kolor punktow,  
     * @param   [const float]       XWINDOW - szerokosc okna,
     * @param   [const float]       YWINDOW - wysokosc okna.
     */
	Fractal(const float XWINDOW, const float YWINDOW);


	/**
     * @fn      [~Fractal]
     * @brief                       wirtualny destruktor dla dziedziczenia, ktory dealokuje zarezerwowana pamiec
     *                              \ na punkty fraktala.
     */
	virtual ~Fractal();


	/**
     * @fn      [CalculatePoints]   
     * @brief                       wirtualna metoda, ktora przelicza punkty fraktala na podstawie 
     *                              \ wylosowanego prawdopodobienstwa - wola ona metode @CalculatePoints oraz @MapAllPoints.
     */
	virtual void CalculatePoints() = 0;


	/**
     * @fn      [CalcProbability] 
     * @brief                       czysto wirtualna metoda, ktora wylicza prawdopodobienstwo, na podstawie ktorego
     *                              \ wolana jest odpowiednia metoda skladowa klasy przypisujaca wspolrzedne punktu do tablicy.
     */
	virtual void CalcProbability() = 0;


	/**
     * @fn      [Map_pointX]         
     * @brief                       czysto wirtualna metoda, ktora mapuje wspolrzedna x punktu fraktala,
     * @param   [float&]            x - wspolrzedna x punktu,
     * @return  [float]             odpowiednio zmapowana nowa wspolrzedna x.
     */
	virtual float Map_pointX(float& x) = 0;


	/**
     * @fn      [Map_pointY]         
     * @brief                       czysto wirtualna metoda, ktora mapuje wspolrzedna y punktu fraktala,
     * @param   [float&]            y - wspolrzedna y punktu,
     * @return  [float]             odpowiednio zmapowana nowa wspolrzedna y.
     */
	virtual float Map_pointY(float& y) = 0;


	/**
     * @fn      [GetX]              
     * @brief                       metoda, ktora zwraca pierwsza wspolrzedna pary punktu przy danym indeksie,
     * 
     * @param   [int]               iter - numer iteracji, a takze indeks pary z ktorej ma byc zwrocony x,
     * @return  [float]             wspolrzedna x danej pary.
     */
	float GetX(int iter)const { return m_xy[iter].first; }
	
	
	/**
     * @fn      [GetY]              
     * @brief                       metoda, ktora zwraca druga wspolrzedna pary punktu przy danym indeksie,
     * 
     * @param   [int]               iter - numer iteracji, a takze indeks pary z ktorej ma byc zwrocony y,
     * @return  [float]             wspolrzedna y danej pary
     */
	float GetY(int iter)const { return m_xy[iter].second; }


	/**
     * @fn      [GetX]              
     * @brief                       metoda, ktora zwraca pierwsza wspolrzedna pary punktu przy danym indeksie,
     *                              \ a takze umozliwia zapis na danej wspolrzednej,
     * 
     * @param   [int]               iter - numer iteracji, a takze indeks pary z ktorej ma byc zwrocony x,
     * @return  [float&]            wspolrzedna x danej pary.
     */
	float& GetX(int iter) { return m_xy[iter].first; }
	

	/**
     * @fn      [GetY]              
     * @brief                       metoda, ktora zwraca pierwsza wspolrzedna pary punktu przy danym indeksie,
     *                              \ a takze umozliwia zapis na danej wspolrzednej,
     * 
     * @param   [int]               iter - numer iteracji, a takze indeks pary z ktorej ma byc zwrocony y,
     * @return  [float&]            wspolrzedna y danej pary.
     */
	float& GetY(int iter) { return m_xy[iter].second; }


	/**
     * @fn      [MapAllPoints]      
     * @brief                       czysto wirtualna metoda, ktora mapuje kazdy punkt fraktala tak, aby
     *                              \ znajdowal sie w obrebie okna.
     */
	virtual void MapAllPoints();


	/**
     * @fn      [UpdateSize]      
     * @brief                       wirtualna metoda, ktora pozwala na zmiane rozmiaru okna i wyswietlanie prawidlowo fraktali,
	 * @param	[float]				x - szerokosc okna,
	 * @param	[float]				y - wysokosc okna.
     */
	virtual void UpdateSize(float x,float y);
protected:
	float m_xwindow;
	float m_ywindow;

	int m_probability;
	int max_iteration = 1;


	std::pair<float, float>* m_xy;

};


Fractal::Fractal(const float XWINDOW, const float YWINDOW) :m_xwindow(XWINDOW), m_ywindow(YWINDOW){
	m_xy = new std::pair<float, float>[ITERATION_MAX];

	m_xy[0].first = XWINDOW / 2.0f;
	m_xy[0].second = YWINDOW / 2.0f;
}

Fractal::~Fractal() {
	delete[] m_xy;
}

void Fractal::MapAllPoints() {
	for (int i = 0; i < ITERATION_MAX; ++i) {
		m_xy[i].first = Map_pointX(m_xy[i].first);
		m_xy[i].second = Map_pointY(m_xy[i].second);
	}
}


void Fractal::UpdateSize(float x, float y) {
	m_xwindow = x;
	m_ywindow = y;
	MapAllPoints();
}
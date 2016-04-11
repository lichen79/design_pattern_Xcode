///////////////////////////////////////////////////////////
//  Product.cpp
//  Implementation of the Class Product
//  Created on:      02-十月-2014 15:57:04
//  Original author: colin
///////////////////////////////////////////////////////////

#include "Product2.h"
#include <iostream>
using namespace std;

Product2::Product2(){

}



Product2::~Product2(){

}

void Product2::setA(string str)
{
	m_a = str;
}

void Product2::setB(string str)
{
	m_b = str;
}

void Product2::setC(string str)
{
	m_c = str;
}

void Product2::show()
{
	cout << "product has" << m_a << m_b << m_c << endl;
}
/**
* @file gamebutton.cpp
* @author Greg VanKampen (gvankampen@upei.ca)
* @version 1.0
*
*
* @section DESCRIPTION
*  a class to format the game button for x's and o's
*
*
* @section LICENSE
* <any necessary attributions>
*
* Copyright 2018 Greg VanKampen
* Permission to use, copy, modify, and/or distribute this software for
* any purpose with or without fee is hereby granted, provided that the
* above copyright notice and this permission notice appear in all copies.
*
* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
* WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
* ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
* ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
* @section Academic Integrity
* I certify that this work is solely my own and complies with
* NBCC Academic Integrity Policy (policy 1111)
*/
#include "gamebutton.h"

GameButton::GameButton(int index, QWidget *parent) : QPushButton(parent), index(index)
{
 QFont font;
 font.setPointSize(10);
 font.setBold(true);
 font.setWeight(10);
 setFont(font);
 setMinimumHeight(20);
 setMinimumWidth(20);
 alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
}

QChar GameButton::getValue() const
{
    return alphabet[index];
}


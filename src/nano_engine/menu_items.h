/*
    MIT License

    Copyright (c) 2019, Alexey Dynda

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/
/**
 * @file menu_items.h Menu items classes
 */

#ifndef _NANO_MENU_ITEMS_H_
#define _NANO_MENU_ITEMS_H_

#include "menu.h"
#include "nano_gfx_types.h"

/**
 * @ingroup NANO_ENGINE_API
 * @{
 */

template<class T>
class NanoMenuTestItem: public NanoMenuItem<T>
{
public:
    NanoMenuTestItem()
       : NanoMenuItem<T>( {0, 0}, {48, 8} )
    {
    }

    void draw() override
    {
        if ( this->isFocused() )
        {
            this->getTiler()->get_canvas().setColor( 0xFFFF );
            this->getTiler()->get_canvas().fillRect( this->m_rect );
        }
        else
        {
            this->getTiler()->get_canvas().setColor( 0 );
            this->getTiler()->get_canvas().fillRect( this->m_rect );
            this->getTiler()->get_canvas().setColor( 0xFFFF );
            this->getTiler()->get_canvas().drawRect( this->m_rect );
        }
    }
};

template<class T>
class NanoMenuTextItem: public NanoMenuItem<T>
{
public:
    NanoMenuTextItem(const uint8_t *font, const char *name)
       : NanoMenuItem<T>( {0, 0} )
       , m_font( font )
       , name( name )
    {
    }

    void draw() override
    {
    }

protected:
    const uint8_t *m_font = nullptr;
    const uint8_t *m_name;
};


/**
 * @}
 */

#endif

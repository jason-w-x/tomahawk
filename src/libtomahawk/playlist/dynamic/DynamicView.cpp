/****************************************************************************************
 * Copyright (c) 2011 Leo Franchi <lfranchi@kde.org>                                    *
 *                                                                                      *
 * This program is free software; you can redistribute it and/or modify it under        *
 * the terms of the GNU General Public License as published by the Free Software        *
 * Foundation; either version 2 of the License, or (at your option) any later           *
 * version.                                                                             *
 *                                                                                      *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY      *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A      *
 * PARTICULAR PURPOSE. See the GNU General Public License for more details.             *
 *                                                                                      *
 * You should have received a copy of the GNU General Public License along with         *
 * this program.  If not, see <http://www.gnu.org/licenses/>.                           *
 ****************************************************************************************/

#include "DynamicView.h"

#include "widgets/overlaywidget.h"
#include "trackmodel.h"

#include <QPainter>
using namespace Tomahawk;


DynamicView::DynamicView( QWidget* parent )
    : PlaylistView( parent )
{
    
}

DynamicView::~DynamicView()
{

}

void 
DynamicView::setModel( TrackModel* model)
{
    PlaylistView::setModel( model );
    
    connect( model, SIGNAL( trackCountChanged( unsigned int ) ), SLOT( onTrackCountChanged( unsigned int ) ) );
}


void 
DynamicView::showMessageTimeout( const QString& title, const QString& body )
{
    m_title = title;
    m_body = body;
    
    overlay()->setText( QString( "%1:\n\n%2" ).arg( m_title, m_body ) );
    overlay()->show( 5 );
}

void 
DynamicView::onTrackCountChanged( unsigned int tracks )
{
    if ( tracks == 0 )
    {
        overlay()->setText( tr( "Add some filters above, and press Generate to get started!" ) );
        overlay()->show();
    }
    else
        overlay()->hide();
}

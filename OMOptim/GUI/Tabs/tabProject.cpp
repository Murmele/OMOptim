﻿// $Id$
/**
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 LICENSE OR 
 * THIS OSMC PUBLIC LICENSE (OSMC-PL). 
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES RECIPIENT'S ACCEPTANCE
 * OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3, ACCORDING TO RECIPIENTS CHOICE. 
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from OSMC, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or  
 * http://www.openmodelica.org, and in the OpenModelica distribution. 
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 * Main contributor 2010, Hubert Thierot, CEP - ARMINES (France)
 * Main contributor 2010, Hubert Thierot, CEP - ARMINES (France)

 	@file tabProject.cpp
 	@brief Comments for file documentation.
 	@author Hubert Thieriot, hubert.thieriot@mines-paristech.fr
 	Company : CEP - ARMINES (France)
 	http://www-cep.ensmp.fr/english/
 	@version 0.9 
*/

#include "tabProject.h"
#include <QtGui/QSortFilterProxyModel>
#include "MOOptPlot.h"


namespace Ui
{
	class TabProject_Class;
}

TabProject::TabProject(Project *project_, QWidget *parent) :
MOTabSimple(project_->name(),project_),ui(new Ui::TabProject_Class)
{
	ui->setupUi(this);

	project = project_;



	// Adding view list in combo
	//viewList << "Infos" << "Variables" << "Components" ;
	//ui->comboDisp->addItems(viewList);

	// View widgets
        widgetInfos = new WidgetProjectInfos(project);
        ui->myLayout->addWidget(widgetInfos);
	//tabVariables = new TabModelVariables(project);
	//ui->myLayout->addWidget(tabVariables);
	//tabComponents = new TabModelComponents(project);
	//ui->myLayout->addWidget(tabComponents);

        widgetInfos->show();
	//tabVariables->hide();
	//tabComponents->hide();

	//curView = -1; // to force actualization
	//updateView(0);

	// Connect signals and slots
	//connect(ui->comboDisp,SIGNAL(activated(int)),
	//	this,SLOT(updateView(int)));
}

TabProject::~TabProject()
{
	delete ui;
}


void TabProject::actualizeGuiFromProject()
{
        widgetInfos->actualizeGuiFromProject();
}
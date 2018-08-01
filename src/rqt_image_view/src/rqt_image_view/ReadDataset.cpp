/*
 * ReadDataset.cpp
 *
 *  Created on: 11/09/2013
 *      Author: gustavo
 */

#include <rqt_image_view/ReadDataset.h>
#include <rqt_image_view/dataset.h>

#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

DatasetPointer ReadDataset::read(std::string filename, int nLabels,int train_data_no) {
	ifstream myFile(filename);

	if (!myFile.is_open()) {
		throw invalid_argument("filename");
	}

	size_t nExamples, nDim;

	nExamples=train_data_no;
	nDim=3;

	//myFile >> nExamples >> nDim;


	cout<<"nExamples: "<<nExamples<<endl<<"nDim: "<<nDim<<endl;

	DatasetPointer result = DatasetPointer(new dataset_base(nExamples,nDim,nLabels));

	for(size_t i = 0; i < nExamples; i++) {
		for (size_t j = 0; j < nDim; j++){
			myFile >> result->pos(i,j);
			cout<<"result-> pos("<<i<<","<<j<<"): "<<result->pos(i,j)<<endl;

		}

		myFile>> result->label(i);
		cout<<"result-> label("<<i<<"): "<<result->label(i)<<endl;
	}

	return result;
}


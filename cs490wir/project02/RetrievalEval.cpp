/*==========================================================================
 * Copyright (c) 2001 Carnegie Mellon University.  All Rights Reserved.
 *
 * Use of the Lemur Toolkit for Language Modeling and Information Retrieval
 * is subject to the terms of the software license set forth in the LICENSE
 * file included with this software, and also available at
 * http://www.lemurproject.org/license.html
 *
 *==========================================================================
*/

/*! \page  Retrieval Evaluation Application within light Lemur toolkit

This application runs retrieval experiments to evaluate different retrieval models 

Usage: RetrievalEval parameter_file

Please refor to the namespace LocalParameter for setting the parameters within the parameter_file

 */


#include "common_headers.hpp"
#include "IndexManager.hpp"
#include "BasicDocStream.hpp"
#include "Param.hpp"
#include "String.hpp"
#include "IndexedReal.hpp"
#include "ScoreAccumulator.hpp"
#include "ResultFile.hpp"
#include "TextQueryRep.hpp"

using namespace lemur::api;

namespace LocalParameter{
  std::string databaseIndex; // the index of the documents
  std::string queryStream;   // the file of query stream
  std::string resultFile;    // the name of the result file
  std::string classResultFile;  // the name of the classification result file
  std::string weightScheme;  // the weighting scheme
  int resultCount;           // the number of top ranked documents to return for each query
  int kNN;
  void get() {
    // the string with quotes are the actual variable names to use for specifying the parameters
    databaseIndex    = ParamGetString("index"); 
    queryStream      = ParamGetString("query");
    resultFile       = ParamGetString("resultFile","res");
    classResultFile  = ParamGetString("classResultFile");
    weightScheme     = ParamGetString("weightScheme","RawTF");
    resultCount      = ParamGetInt("resultCount", 200);
    kNN       = ParamGetInt("kNN", 100);
  }    
};

void GetAppParam() 
{
  LocalParameter::get();
}

// compute the weight of a matched term
double computeRawTFWeight(int docID,
         int termID, 
         int docTermFreq, 
         double qryTermWeight,
         Index *ind)
{
  //implementation of raw TF weighting scheme
  return docTermFreq*qryTermWeight;
}


// compute the weight of a matched term
double computeRawTFIDFWeight(int docID,
         int termID, 
         int docTermFreq, 
         double qryTermWeight,
         Index *ind)
{
  //implementation of raw TF and IDF weighting scheme
  int totalNumDocs=ind->docCount();
  int numDocsContain=ind->docCount(termID);
  return docTermFreq*log((double)totalNumDocs/((double)numDocsContain+1))*qryTermWeight;
}


// compute the weight of a matched term
double computeOkapiWeight(int docID,
         int termID, 
         int docTermFreq, 
         double qryTermWeight,
         Index *ind)
{
  //implementation of Okapi weighting scheme
  int len=ind->docLength(docID);
  int avgDocLen=ind->docLengthAvg();
  int totalNumDocs=ind->docCount();
  int numDocsContain=ind->docCount(termID);
  return (docTermFreq/(docTermFreq+0.5+(1.5*len/avgDocLen)))*log(((double)totalNumDocs-((double)numDocsContain+0.5))/((double)numDocsContain+0.5))*((8+qryTermWeight)/(7+qryTermWeight));
}



// compute the adjusted score
double computeAdjustedScore(double origScore, // the score from the accumulator
          int docID, // doc ID
          Index *ind) // index
{
  //Do nothing now
  return origScore;
}


void ComputeQryArr(Document *qryDoc, double *qryArr, Index *ind){
  //compute the array representation of query; it is the frequency representation for the original query 
  for (int t=1; t<=ind->termCountUnique(); t++) {
    qryArr[t]=0;
  }
  
  qryDoc->startTermIteration();
  while (qryDoc->hasMore()) {
    const Term *qryTerm = qryDoc->nextTerm();
    int qryTermID = ind->term(qryTerm->spelling());
    qryArr[qryTermID] ++;
  }
}

void Retrieval(double *qryArr, IndexedRealVector &results, Index *ind){
  //retrieve documents with respect to the array representation of the query

  lemur::retrieval::ArrayAccumulator scoreAccumulator(ind->docCount());

  scoreAccumulator.reset();
  for (int t=1; t<=ind->termCountUnique();t++) {
    if (qryArr[t]>0) {      
      // fetch inverted entries for a specific query term
      DocInfoList *docList = ind->docInfoList(t);

      // iterate over all individual documents 
      docList->startIteration();
      while (docList->hasMore()) {
        DocInfo *matchInfo = docList->nextEntry();
        // for each matched term, calculated the evidence

        double wt;

        if (strcmp(LocalParameter::weightScheme.c_str(),"RawTF")==0) {
          wt = computeRawTFWeight(matchInfo->docID(),  // doc ID
                t, // term ID
                matchInfo->termCount(), // freq of term t in this doc
                qryArr[t], // freq of term t in the query
                ind);    
        }else if (strcmp(LocalParameter::weightScheme.c_str(),"RawTFIDF")==0) {
          wt = computeRawTFIDFWeight(matchInfo->docID(),  // doc ID
                t, // term ID
                matchInfo->termCount(), // freq of term t in this doc
                qryArr[t], // freq of term t in the query
                ind);    
        }else if (strcmp(LocalParameter::weightScheme.c_str(),"Okapi")==0) {
          wt = computeOkapiWeight(matchInfo->docID(),  // doc ID
                t, // term ID
                matchInfo->termCount(), // freq of term t in this doc
                qryArr[t], // freq of term t in the query
                ind);    
        }else{
          cerr<<"The weighting scheme of "<<LocalParameter::weightScheme.c_str()<<" is not supported"<<endl;
                exit(1);
        }
        scoreAccumulator.incScore(matchInfo->docID(),wt);  
      }
      delete docList;
    }
  }

  // Adjust the scores for the documents when it is necessary
  double s;
  int d;
  for (d=1; d<=ind->docCount(); d++) {
    if (scoreAccumulator.findScore(d,s)) {
    } else {
      s=0;
    }

    if (strcmp(LocalParameter::weightScheme.c_str(),"RawTF")==0) {
      results.PushValue(d, computeAdjustedScore(s, // the score from the accumulator
            d, // doc ID
            ind)); // index
    }else if (strcmp(LocalParameter::weightScheme.c_str(),"RawTFIDF")==0) {
      results.PushValue(d, computeAdjustedScore(s, // the score from the accumulator
            d, // doc ID
            ind)); // index
    }else if (strcmp(LocalParameter::weightScheme.c_str(),"Okapi")==0) {
      results.PushValue(d, computeAdjustedScore(s, // the score from the accumulator
            d, // doc ID
            ind)); // index
    }else{
      cerr<<"The weighting scheme of "<<LocalParameter::weightScheme.c_str()<<" is not supported"<<endl;
      exit(1);
    }
  }
}

// perform the K nearest neighbor Email spam categorization
void performKNNCategorization(string res_file_name, string classification_res_file_name)
{
  // use the retrieval results for categorization
  ifstream result_file(&res_file_name[0]);
  ofstream cat_result_file(&classification_res_file_name[0]); // categorization output file

  // for each query document, assign a class value and write it to the result file
  for (int j=0; j < 200 ; j++ )
  {
    // the format of the result file is this, parse it line by line      
    string query_id, temp, doc_name, temp2, score, temp3;

    int numOfRegular = 0;
    int numOfSpam = 0;

    // set the k of the k-NN parameter
    int k = LocalParameter::kNN;

    for (int i=0; (!result_file.eof()) && (i < LocalParameter::resultCount); i++)
    {
      result_file >> query_id >> temp >> doc_name >> temp2 >> score >> temp3;
  
      // only consider the nearest k docs for categorization
      if (i < k)
      {
        if (doc_name.substr(0,2) == "r_") // have seen a regular email, name beginning with 'r_' indicates a regular email
        {          
          numOfRegular++; // increment the number of regular emails
        }
        else if (doc_name.substr(0,2) == "s_") // have seen a regular email, name beginning with 's_' indicates a spam email
        {
          numOfSpam++; // increment the number of spam emails
        }
      }
    }
        
    // assign the class 
    string class_of_query_doc = "";  
    
    // assign the appropriate class value for the current query
    if (numOfRegular > numOfSpam)
      class_of_query_doc = "r"; // r for regular email
    else
      class_of_query_doc = "s"; // s for spam email

    cout << "#regular:" << numOfRegular << " - #spam:" << numOfSpam << " => class :" << class_of_query_doc << endl;
    cat_result_file << query_id << " " << class_of_query_doc << endl;
  }
  cat_result_file.close();
  result_file.close();
}



/// A retrieval evaluation program
int AppMain(int argc, char *argv[]) {
  

  //Step 1: Open the index file
  Index  *ind;

  try {
    ind  = IndexManager::openIndex(LocalParameter::databaseIndex);
  } 
  catch (Exception &ex) {
    ex.writeMessage();
    throw Exception("RelEval", "Can't open index, check parameter index");
  }

  //Step 2: Open the query file
  DocStream *qryStream;
  try {
    qryStream = new lemur::parse::BasicDocStream(LocalParameter::queryStream);
  } 
  catch (Exception &ex) {
    ex.writeMessage(cerr);
    throw Exception("RetEval", 
                    "Can't open query file, check parameter textQuery");
  }

  //Step 3: Create the result file
  ofstream result(LocalParameter::resultFile.c_str());
  ResultFile resultFile(1);
  resultFile.openForWrite(result, *ind);


  // go through each query
  qryStream->startDocIteration();
  while (qryStream->hasMore()) {
    Document *qryDoc = qryStream->nextDoc();
    const char *queryID = qryDoc->getID();
    cout << "query: "<< queryID <<endl;

    double *queryArr = new double[ind->termCountUnique()+1];  //the array that contains the weights of query terms; for orignial query 
    ComputeQryArr(qryDoc,queryArr, ind); 

    IndexedRealVector results(ind->docCount());
    results.clear();

    // DO THE RETRIEVAL
    Retrieval(queryArr,results,ind);

    results.Sort();
    resultFile.writeResults(queryID, &results, LocalParameter::resultCount);

    delete queryArr;
  }
  result.close();
  delete ind;

 
  // DO THE k-NN Email Spam Categorization
  performKNNCategorization( LocalParameter::resultFile.c_str(), LocalParameter::classResultFile.c_str());

  return 0;
}


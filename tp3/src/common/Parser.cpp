#include "Parser.h"

void splitString(vector<string>* out, string str, string delimiter) {
    unsigned long fromIndex = 0;
    unsigned long delimiterIndex = 0;
    while((delimiterIndex = str.find(delimiter, fromIndex)) != -1) {
        out->push_back(str.substr(fromIndex, delimiterIndex));
        fromIndex = delimiterIndex + delimiter.length();
    }
    out->push_back(str.substr(fromIndex, delimiterIndex));
}

Parser::Parser() 
{
	
}

void Parser::parseInput() 
{
	vector<string> inputLines;    
    string line;   
    while(getline(cin, line)) {    	
    	if(line == "0") break;    	
        inputLines.push_back(line);        
    }    

    int currLine = 0;
    while(currLine < inputLines.size()) {
    	vector<string> stringsList;
	    splitString(&stringsList, inputLines[0], " ");
	    int n = atoi(stringsList[0].c_str());
	    int m = atoi(stringsList[1].c_str());
	    int u = atoi(stringsList[2].c_str());
	    int v = atoi(stringsList[3].c_str());
	    int K = atoi(stringsList[4].c_str());    
		        
	    currLine++;	    

	    Graph* graph = new Graph(n);	    
	    for (int i=0; i<m; i++) {	    	
	        vector<string> edge;
	        splitString(&edge, inputLines[currLine+i], " ");	        	       
	        int v1 = atoi(edge[0].c_str());
	        int v2 = atoi(edge[1].c_str());
	        int w1 = atoi(edge[2].c_str());
	        int w2 = atoi(edge[3].c_str());	        
	        graph->addEdge(v1, v2, w1, w2);	        
	    }	    

	    ProblemInstance* instance = new ProblemInstance();
	    instance->graph = graph;
	    instance->u = u;
	    instance->v = v;
	    instance->K = K;
	    problemInstances.push_back(instance);

	    currLine += m;
    }
}

Parser::~Parser() 
{
	while(!problemInstances.empty()) {
		delete problemInstances.back(); 
		problemInstances.pop_back();
	}
}
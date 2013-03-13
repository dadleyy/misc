#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

#include "rapidjson/document.h"		// rapidjson's DOM-style API
#include "rapidjson/prettywriter.h"	// for stringify JSON



using namespace std;

struct Vertex {
    float x, y, z;
};

namespace parsers {
    
    std::vector<std::string> &split( const std::string &s, char delim, std::vector<std::string> &elems ) {
        std::stringstream ss( s );
        std::string item;
        while(std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
    
    std::vector<std::string> split( const std::string &s, char delim ) {
        std::vector<std::string> elems;
        return split(s, delim, elems);
    }
    
    Vertex ParseVertexString( string line ) {
        Vertex v = { 0.0f, 0.0f, 0.0f };
        
        string _vals = line.substr( 2, line.length() - 2 );
        vector<string> _nums = split( _vals, ' ' );
        
        v.x = atof( _nums[0].c_str( ) );
        v.y = atof( _nums[1].c_str( ) );
        v.z = atof( _nums[2].c_str( ) );
        
        return v;
    }
}

int main(int argc, const char *argv[]) {
    
    string _inFileN = "",
           _outFileN = "";
    
    for ( int i = 0; i < argc; i ++ ) {
        string arg = (string)argv[i];
        if ( arg == "-i" ) {
            _inFileN = ( i < argc - 1 ) ? argv[i+1] : "";
        } else if ( arg == "-o" ) {
            _outFileN = ( i < argc - 1 ) ? argv[i+1] : "out.json";
        }
    }
    
    /* make sure we have file names at this point */
    if ( _inFileN == "" || _outFileN == "" ) {
        cout << "!- Please specify an input and an output file using the -i and -o flags" << endl;
        return 0;
    }
    
    ifstream _reader;
    ofstream _writer;
    
    /* attempt to load the .obj file */
    cout << ".- Attempting to load: " << _inFileN << endl;
    _reader.open( _inFileN );
    if ( !_reader.good() ) {
        cout << "!- Could not open the specified input file" << endl;
        return 0;
    }
    cout << "+- Successfully opened the input file" << endl;
    
    /* attempt to open up the output file */
    cout << ".- Attempting to open " << _outFileN << " to write into" << endl;
    _writer.open( _outFileN );
    if ( !_writer.good() ) {
        cout << "!- Could not open the output file" << endl;
        return 0;
    }
    cout << "+- Successfully opened the output file" << endl;
    
    string _line = "",
           _flag = "";
    
    int vcount = 0,
        icount = 0;
    
    /* loop through the file */
    while ( getline( _reader, _line ) ) {
        _flag = { _line[0], _line[1] };
        
        /* Start checking the first letter
         * of the current line. This letter
         * tells us what will be comint next
        */
        /* vertex definition "x.xxx y.yyy z.zzz" */
        if( _flag == "v " ) {
            Vertex v = parsers::ParseVertexString( _line );
            cout << "~ Vertex: (" << v.x << " , " << v.y << " , " << v.z << " ) " << endl;
            vcount++;
        }
        /* face definition (indices for DirectX) */
        else if ( _flag == "f " ) {
         
            icount ++;
        }
        /* vertext texture coordinates */
        else if ( _flag == "vt" ) {
            
        }
        /* vertex normal condition */
        else if ( _flag == "vn" ) {
            
        } else {
            
        }
        
        _flag = "";
    }
    cout << "- found [ " << vcount << " ] vertices" << endl;
    
    /* start the json output */
    _writer << "{ \n \"version\" : \"1.0\" \n ";
    /* close the json output */
    _writer << "}";
    
    _writer.close( );
    _reader.close( );
    
    
    ifstream ifs( _outFileN );
    string json( (std::istreambuf_iterator<char>(ifs) ), (std::istreambuf_iterator<char>() ) );
    
    rapidjson::Document document;
    if( document.Parse<0>( json.c_str() ).HasParseError() ) {
        cout << "!- Failed to parse output json...build failed." << endl;
    } else {
        cout << "+- Successfully made json output. (Version: " << document["version"].GetString() << ")" << endl;
    }
    
    
    return 0;
}


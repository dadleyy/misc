/* */
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
    float x, y, z, n;
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
    
    void ParseFaceString( string line, int *inSet ) {
        string _vals = line.substr( 2, line.length() - 2 );
        vector<string> _sets = split( _vals, ' ' );
        for ( int i = 0; i < 3; i ++ ) {
            string ind = _sets[i].substr( 0, 1 );
            inSet[i] = atoi( ind.c_str( ) );
        }
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
    
    
    /* initialize variables that will update for each line */
    string _line = "",
           _flag = "";
    
    /* keep track of verts and indices */
    int vcount = 0,
        icount = 0;
    
    vector<Vertex> _verts;
    vector<int> _indices;
    
    /* loop through the file */
    while ( getline( _reader, _line ) ) {
        
        /* the first two chars of the line tell us what kind of thing it is */
        _flag = { _line[0], _line[1] };
        
        /* Start checking the first letter
         * of the current line. This letter
         * tells us what will be comint next
        */
        /* vertex definition "x.xxx y.yyy z.zzz" */
        if( _flag == "v " ) {
            Vertex v = parsers::ParseVertexString( _line );
            _verts.push_back( v );
            cout << "~ Vertex: (" << v.x << " , " << v.y << " , " << v.z << " ) " << endl;
            vcount++;
        }
        /* face definition (indices for DirectX) */
        else if ( _flag == "f " ) {
            int face[3] = { 0, 0, 0 };
            parsers::ParseFaceString( _line, face );
            for ( int z = 0; z < 3; z++ ) {
                _indices.push_back( face[z] );
                icount ++;
            }
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
    cout << "~ indices order: " << endl << "~ ";
    for ( int i = 1; i <= _indices.size(); i++ ) {
        cout << _indices[i-1] << " ";
        if ( (i % 10) == 0 ) { cout << endl << "~ "; }
    }
    cout << endl;
    
    cout << "- found [ " << vcount << " ] vertices : " << _verts.size() << endl;
    cout << "- found [ " << icount << " ] indices : " << _indices.size() << endl;
    
    /* start the json output */
    _writer << "{ \n \"version\" : \"1.0\", \n";
    
    /* write the vertices out */
    _writer << " \"vertices\" : [ ";
    
    for ( int i = 0; i < _verts.size(); i++ ) {
        string _vstring = " { \"x\" : \"";
        
        std::ostringstream ss;
        
        /* add the x value */
        ss << _verts[i].x;
        _vstring.append( ss.str() );
        _vstring.append( "\"," );
        
        ss.str("");
        ss.clear();
        
        /* add the y value */
        ss << _verts[i].y;
        _vstring.append( "\"y\" : \"" );
        _vstring.append( ss.str() );
        _vstring.append( "\"," );
        
        ss.str("");
        ss.clear();
        
        /* add the z value */
        ss << _verts[i].z;
        _vstring.append( "\"z\":\"" );
        _vstring.append( ss.str() );
        _vstring.append( "\"" );
        
        ss.str("");
        ss.clear();
        
        /* close the string */
        _vstring.append( " }");
        if ( i != _verts.size() - 1 ) { _vstring.append(","); }
        
        _writer << _vstring;
    }
    
    _writer << " ], \n";
    
    _writer << " \"indices\" : [ ";
    
    for ( int i = 0; i < _indices.size(); i++ ) {
        _writer << _indices[i];
        if ( i != _indices.size() - 1 ) { _writer << ","; }
    }
    
    _writer << " ] \n";
    
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


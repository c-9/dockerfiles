/*******************************************************************************
* Copyright (c) 2012-2014, The Microsystems Design Labratory (MDL)
* Department of Computer Science and Engineering, The Pennsylvania State University
* All rights reserved.
* 
* This source code is part of NVMain - A cycle accurate timing, bit accurate
* energy simulator for both volatile (e.g., DRAM) and non-volatile memory
* (e.g., PCRAM). The source code is free and you can redistribute and/or
* modify it by providing that the following conditions are met:
* 
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
* 
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
* Author list: 
*   Matt Poremba    ( Email: mrp5060 at psu dot edu 
*                     Website: http://www.cse.psu.edu/~poremba/ )
*******************************************************************************/

#ifndef __NVMAIN_HELPERS_H__
#define __NVMAIN_HELPERS_H__

#include <string>
#include <map>
#include <cstdint>
#include <sstream>

namespace NVM {
/*template <class T>
int mlog2( int num );*/

template <class T>
int mlog2( T num )
{
    int retVal = -1;
    T newNum = num;

    if( num < 2 )
        return 0;

    while( newNum != 0 )
    {
        retVal++;
        newNum >>= 1;
    }
    return retVal;
}
std::string GetFilePath( std::string file );

template <typename T1, typename T2>
std::string PyDictHistogram( std::map<T1, T2> iiMap )
{

    /* Print a histogram as a python-style dict. */
    std::stringstream pyHistoSS;

    pyHistoSS.str("");
    pyHistoSS << "{";

    bool outputComma = false;
    for( typename std::map<T1, T2>::iterator iter = iiMap.begin();
         iter != iiMap.end(); ++iter )
    {
        if( outputComma )
            pyHistoSS << ", ";

        pyHistoSS << iter->first;
        pyHistoSS << ": ";
        pyHistoSS << iter->second;

        outputComma = true;
    }

    pyHistoSS << "}";

    return pyHistoSS.str();
}


};

#endif

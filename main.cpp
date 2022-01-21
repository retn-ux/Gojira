#include "GojiraDefs.h"
#include "GContainer.h"
#include "GProcess.h"
#include "GMemory.h"
#include <iostream>
using namespace std;
int main(){
    cout<<"program start"<<endl;
    MemoryManager mm;
    void* address=mm.alloc(0,0x1000,MemoryImpl::MemoryProtect::PageRead);
    if(address==nullptr){
        cout<<"alloc error"<<endl;
        return 0;
    }
    cout<<"0x" << hex << reinterpret_cast<Gauge>(address) << endl;
    if(mm.free(address, 0x1000) == GErrCode::SUCCESS){
        cout<<"free error"<<endl;
        return 0;
    }

    cout<<"program end"<<endl;
    return 0;

}
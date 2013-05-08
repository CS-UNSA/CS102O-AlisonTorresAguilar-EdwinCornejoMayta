#include "Lexer.h"

Lexer::Lexer()
{

}
Lexer::~Lexer()
{

}

bool Lexer::verificarPR(char * pal){
    
    for (register int i = 0; i<sizeof(palReservadas)/sizeof(string);++i ) {
        if(pal==palReservadas[i])
            return true;
    }
    
    return false;
}

bool Lexer::verificarTD(char * pal){
    
    for (register int i = 0; i<sizeof(tipoDato)/sizeof(string);++i ) {
        if(pal==tipoDato[i])
            return true;
    }
    
    return false;
}

bool Lexer::verificarOp(char * pal){
    
    for (register int i = 0; i<sizeof(operador)/sizeof(string);++i ) {
        if(pal==operador[i])
            return true;
    }
    
    return false;
}

bool Lexer::verificarDi(char * pal){
    
    //for (register int i = 0; i<str;++i ) {
       if(isdigit(*pal))
            return true;
    //}
    
    return false;
}



void Lexer::analizar(char* inpf, char* outf){
    // ESTA FUNCION SOLO DEBERIA DE ABRIR EL FICHERO Y LLAMAR A UN METODO QUE ANALIZE ASI PODRIA EN MI ANALIZAR AVANZADO SOLO LLAMAR A LA NUEVA FUNCION PRACTIMANTE SOLO ROMPERIA SI ESTA TODO JUNTO Y LO MANDARIA A EVALUAR 
    ifstream file(inpf);
    ofstream fSalida(outf);
    char buffer[1000];
    while (!file.eof()) {
        file>>buffer;
        if (!crearToken(buffer, fSalida)) {
            
        
        // DESDE AQUI SERIA LA FUNCION
   /*     if(this->verificarPR(buffer)){
            cout<<buffer<<" : PALABRA RESERVADA"<<endl;
            fSalida<<buffer<<" : PALABRA RESERVADA"<<endl;
        }
        
        else if(this->verificarTD(buffer)){
            cout<<buffer<<" : TIPO DE DATO"<<endl;
            fSalida<<buffer<<" : TIPO DE DATO"<<endl;
        }
        
        else if(verificarDi(buffer)){
         cout<<buffer<<" : DIGITO"<<endl;
         fSalida<<buffer<<" : DIGITO"<<endl;
         }
        else if(verificarOp(buffer)){
            cout<<buffer<<" : OPERADOR"<<endl;
            fSalida<<buffer<<" : OPERADOR"<<endl;
        }
        else if(verificarCo(buffer)){
            cout<<buffer<<" : COMENTARIO"<<endl;
            fSalida<<buffer<<" : COMENTARIO"<<endl;
        }
        else if(verificarCe(buffer)){
            cout<<buffer<<" : CARACTER DE ESCAPE"<<endl;
            fSalida<<buffer<<" : CARACTER DE ESCAPE"<<endl;
        }
        else if(verificarOt(buffer)){
            cout<<buffer<<" : ESPECIAL"<<endl;
            fSalida<<buffer<<" : ESPECIAL"<<endl;
        }*/
        // HASTA AQUI
       // else{//tener cuidado aqui se filtran los errores
            if(!this->analizarAvanzado(buffer,fSalida)){
            //this->analizarAvanzado(buffer);
          //  cout<<buffer<<" : IDENTIFICADOR"<<endl;
            //fSalida<<buffer<<" : IDENTIFICADOR"<<endl;
            }
        
        }
        
        
    }
    

}
void Lexer::limpiarBuffer(char* buffer){
    //cout<<strlen(buffer)<<endl;
    string tmp = buffer;
    tmp.replace(0, tmp.size(),"");
    strcpy (buffer, tmp.c_str());
    
}
void Lexer::strcopiar(char* buffer,char* bufferCopia, int ini,int fin){
   // bufferCopia[0]='\0';
    this->limpiarBuffer(bufferCopia);
    for (int i = 0; i<(fin-ini); ++i) {
        bufferCopia[i]=buffer[ini+i];
    }
    
    
}

bool Lexer::analizarAvanzado(char* buffer,ofstream &fSalida){
   //revisar esta parte no esta leyendo si estan juntos (toda la funcion)
    string tmp = buffer;
    int ini = 0;
    int fin = (int)tmp.size();
    //(int)tmp.size();
    string sstr;
    string sstr2;
    int i;
    for ( i=ini+1; i<=fin; ++i) {
        sstr = tmp.substr(ini,i-ini);
        //if(i<fin){
                sstr2 = tmp.substr(ini,2);
            if(i<fin&&crearToken((char*)sstr2.c_str(), fSalida)){
                ini=i+1;
                ++i;
                //sstr = tmp.substr(ini,i-ini);
          //  }
        }
        
       else if (crearToken((char*)sstr.c_str(), fSalida)) {
            ini=i;
        }
        
    }
    if(ini==fin)
        return true;
    else{
        cout<<sstr<<" : IDENTIFICADOR"<<endl;
        fSalida<<sstr<<" : IDENTIFICADOR"<<endl;
    }
    /*
    for (int i = 1; i<=tmp.size(); ++i) {
        char subc[500] ;
    //    strcpy(subc, buffer);
        string sub = tmp.substr (ini,i);
        strcpy(subc,sub.c_str());
        if(crearToken(subc, fSalida)){
            tmp.erase (0,i);
        }
    
    }
    if (tmp.size()==0) {
        return true;
    }*/
    return false;
}

bool Lexer::verificarCo(char* pal){
    //for (register int i = 0; i<sizeof(tipoDato)/sizeof(string);++i ) {
  /*  if(pal[0]=='/'){
        if(pal[1]=='/')
            return true;
        else if (pal[1]=='*')
            return true;
        else
            return false;
    }
    else if (pal[0]=='*'&&pal[1]=='/')
        return true;
    
    return false;*/
    for (register int i = 0; i<sizeof(comentario)/sizeof(string);++i ) {
        if(pal==comentario[i])
            return true;
    }
    
    return false;
}

bool Lexer::verificarCe(char * pal){
    for (register int i = 0; i<sizeof(caracterEscape)/sizeof(string);++i ) {
        if(pal==caracterEscape[i])
            return true;
    }
    
    return false;
}

bool Lexer::verificarOt(char * pal){
    for (register int i = 0; i<sizeof(otrosEspeciales)/sizeof(string);++i ) {
        if(pal==otrosEspeciales[i])
            return true;
    }
    
    return false;
}
bool Lexer::crearToken(char* buffer,ofstream &fSalida){
    if(this->verificarPR(buffer)){
        cout<<buffer<<" : PALABRA RESERVADA"<<endl;
        fSalida<<buffer<<" : PALABRA RESERVADA"<<endl;
        return true;
    }
    
    else if(this->verificarTD(buffer)){
        cout<<buffer<<" : TIPO DE DATO"<<endl;
        fSalida<<buffer<<" : TIPO DE DATO"<<endl;
        return true;
    }
    
    else if(verificarDi(buffer)){
        cout<<buffer<<" : DIGITO"<<endl;
        fSalida<<buffer<<" : DIGITO"<<endl;
        return true;
    }
    else if(verificarOp(buffer)){
        cout<<buffer<<" : OPERADOR"<<endl;
        fSalida<<buffer<<" : OPERADOR"<<endl;
        return true;
    }
    else if(verificarCo(buffer)){
        cout<<buffer<<" : COMENTARIO"<<endl;
        fSalida<<buffer<<" : COMENTARIO"<<endl;
        return true;
    }
    else if(verificarCe(buffer)){
        cout<<buffer<<" : CARACTER DE ESCAPE"<<endl;
        fSalida<<buffer<<" : CARACTER DE ESCAPE"<<endl;
        return true;
    }
    else if(verificarOt(buffer)){
        cout<<buffer<<" : ESPECIAL"<<endl;
        fSalida<<buffer<<" : ESPECIAL"<<endl;
        return true;   
    }
    else
        return false;
    return false;
}


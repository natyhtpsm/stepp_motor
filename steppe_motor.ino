int Pin0 = 8;
int Pin1 = 9;
int Pin2 = 10;
int Pin3 = 11;

int _passo = 512; 
int _velocidade = 1; 
void setup()
{
 pinMode(Pin0, OUTPUT);
 pinMode(Pin1, OUTPUT);
 pinMode(Pin2, OUTPUT);
 pinMode(Pin3, OUTPUT);
}

void loop()
{
  Velocidade(15);
  Passo(512);
  delay(2000);
  Velocidade(1); 
  Passo(-512);  
  delay(2000);
}
void Velocidade(int steppervelocidade)
{
    _velocidade = 15 - steppervelocidade;
    if( _velocidade<1){
     _velocidade = 1;
    }
    if( _velocidade>15){
     _velocidade = 15;
    }
}
void Passo(int _passo)/
{
  if(_passo>=0){ 
    for(int i=0;i<_passo;i++){   
      setpasso(1, 0, 0, 1);
      delay(_velocidade); 
      setpasso(1, 0, 0, 0);
      delay(_velocidade);
      setpasso(1, 1, 0, 0);
      delay(_velocidade);
      setpasso(0, 1, 0, 0);
      delay(_velocidade);
      setpasso(0, 1, 1, 0);
      delay(_velocidade);
     setpasso(0, 0, 1, 0);
      delay(_velocidade);
     setpasso(0, 0, 1, 1);
      delay(_velocidade); 
      setpasso(0, 0, 0, 1);
      delay(_velocidade);
    }
  }else{ 
     for(int i=_passo;i<0;i++){  
      setpasso(0, 0, 0, 1);
      delay(_velocidade);
      setpasso(0, 0, 1, 1);
      delay(_velocidade);
      setpasso(0, 0, 1, 0);
      delay(_velocidade);
      setpasso(0, 1, 1, 0);
      delay(_velocidade);
     setpasso(0, 1, 0, 0);
      delay(_velocidade);
      setpasso(1, 1, 0, 0);
      delay(_velocidade);
      setpasso(1, 0, 0, 0);
      delay(_velocidade);
      setpasso(1, 0, 0, 1);
      delay(_velocidade);
    }
   }
}
void setpasso(int a, int b, int c, int d)  
{  
    digitalWrite(Pin0, a);     
    digitalWrite(Pin1, b);     
    digitalWrite(Pin2, c);     
    digitalWrite(Pin3, d);     
}  

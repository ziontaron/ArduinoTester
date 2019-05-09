
int ADDR_Device = 0;
int ADDR_OP = 100;
int ADDR_ssid = 200;
int ADDR_password = 300;
int ADDR_PartsProd = 400;

void CFG_SAVE()
{
  
}

void CFG_LOAD()
{
}

void EEPROM_SAVE(String x,int ADDR)
{
  for(int i=0; i<x.length(); i++)
  {
    EEPROM.write(ADDR, x[i]);
  }
}

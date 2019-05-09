
int ADDR_Device = 0;
int ADDR_OP = 1;
int ADDR_ssid = 100;
int ADDR_password = 200;
int ADDR_PartsProd = 300;

void CFG_SAVE()
{ 
  EEPROM_SAVE(Device,ADDR_Device);
  EEPROM_SAVE(OP,ADDR_OP);
  EEPROM_SAVE(ssid,ADDR_ssid);
  EEPROM_SAVE(password,ADDR_password);
  EEPROM_SAVE(PartsProd,ADDR_PartsProd);
}

void CFG_LOAD()
{
}

void EEPROM_SAVE(String x,int ADDR)
{
  for(int i=0; i<x.length(); i++)
  {
    EEPROM.write(ADDR+i, x[i]);
  }
}

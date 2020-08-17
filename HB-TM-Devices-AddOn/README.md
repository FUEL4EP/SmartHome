
# HB-TM-Devices-AddOn


## Unterstützte Geräte

- [HB-UNI-Sensor1](https://github.com/TomMajor/SmartHome/tree/master/HB-UNI-Sensor1)
- [HB-SEN-LJet](https://github.com/TomMajor/SmartHome/tree/master/HB-SEN-LJet)
- [HB-UNI-Sensor-Heizung](https://github.com/TomMajor/SmartHome/tree/master/HB-UNI-Sensor-Heizung)
- [NEU: HB-UNI-Sensor1-CO2_SCD30](https://github.com/FUEL4EP/SmartHome/tree/HB-UNI-Sensor1-CO2_SCD30/HB-UNI-Sensor1-CO2_SCD30)

[comment]: # (rc.d filename: hb-tm-devices-addon, github name: HB-TM-Devices-AddOn, info name: HB-TM-Devices AddOn)

## Change Log

- 2.50 - 17.05.2020
  - das neue HB-TM-Devices-AddOn orientiert sich an Jérômes JP-HB-Devices-addon und fasst die Unterstützung für meine HomeBrew-Geräte in einem AddOn zusammen.
  - in der ersten Version unterstützt das AddOn die Geräte HB-UNI-Sensor1, HB-SEN-LJet und HB-UNI-Sensor-Heizung.
  - die bisherigen separaten AddOn für diese Geräte sind dadurch hinfällig und werden nicht mehr supported.
  - :warning: bitte unbedingt vor Installation des HB-TM-Devices-AddOn die alten HB-UNI-Sensor1 AddOn und HB-SEN-LJet AddOn deinstallieren, falls vorhanden!
  - HB-UNI-Sensor-Heizung hat ab sofort ein eigenes Device Model bekommen (0xF105) da ich im xml einen neuen Datenpunkt *Fehler* für Störungsmeldungen eingeführt habe.
  
- 2.61 - 17.08.2020 von FUEL4EP
  - Modifikationen und Ergänzungen von FUEL4EP für den neuen CO2 Sensor HB-UNI-Sensor1-CO2_SCD30.
  - Die Änderungen und Ergänzungen sind der Heizungssteuerung HB-UNI-Sensor-Heizung nachempfunden.
  - hinzugefügt: HB-TM-Devices-AddOn/CCU_RM/src/addon/firmware/rftypes/hb-uni-sensor-CO2-SCD30.xml
  - hinzugefügt: HB-TM-Devices-AddOn/CCU_RM/src/addon/install_hb-uni-sensor-CO2-SCD30
  - hinzugefügt: HB-TM-Devices-AddOn/CCU_RM/src/addon/uninstall_hb-uni-sensor-CO2-SCD30
  - hinzugefügt: HB-TM-Devices-AddOn/CCU_RM/src/addon/www/config/img/devices/50/hb-uni-sensor-CO2-SCD30_thumb.png
  - hinzugefügt: HB-TM-Devices-AddOn/CCU_RM/src/addon/www/config/img/devices/250/hb-uni-sensor-CO2-SCD30.png
  - neu erstellt: HB-TM-Devices-AddOn/CCU_RM/hb-tm-devices-addon.tgz


## Eingestellte AddOn

###### Change Log HB-UNI-Sensor1 AddOn (nicht mehr supported)

- 2.04 - 01.01.2020
  - Im xml die Einträge für `<special_value id="NO_SENSOR" value=..` entfernt (wirkungslos, Danke Jérôme).
  - Im xml den HUMIDITY Eintrag auf Bereich 0..100% geändert (% erzwingt Basis 100 in HM, Bereich 1..99% führte zu minimal falschen Kommastellen in ioBroker, Danke harvey).

- (2.50) - 17.05.2020
  - Das AddOn wird nicht mehr fortgeführt. Bitte das neue HB-TM-Devices-AddOn verwenden.

###### Change Log HB-SEN-LJet AddOn (nicht mehr supported)

- (2.50) - 17.05.2020
  - Das AddOn wird nicht mehr fortgeführt. Bitte das neue HB-TM-Devices-AddOn verwenden.

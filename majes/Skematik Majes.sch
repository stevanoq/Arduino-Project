<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="99" name="SpiceOrder" color="5" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="ESP32 DEVKIT V1">
<packages>
<package name="ARDUINOUNO">
<pad name="NC" x="-13.97" y="6.35" drill="0.6" shape="square"/>
<pad name="IOREF" x="-13.97" y="5.08" drill="0.6" shape="square"/>
<pad name="RES" x="-13.97" y="3.81" drill="0.6" shape="square"/>
<pad name="3.3V" x="-13.97" y="2.54" drill="0.6" shape="square"/>
<pad name="5V" x="-13.97" y="1.27" drill="0.6" shape="square"/>
<pad name="GND" x="-13.97" y="0" drill="0.6" shape="square"/>
<pad name="GND1" x="-13.97" y="-1.27" drill="0.6" shape="square"/>
<pad name="VIN" x="-13.97" y="-2.54" drill="0.6" shape="square"/>
<pad name="A0" x="-13.97" y="-5.08" drill="0.6" shape="square"/>
<pad name="A1" x="-13.97" y="-6.35" drill="0.6" shape="square"/>
<pad name="A2" x="-13.97" y="-7.62" drill="0.6" shape="square"/>
<pad name="A3" x="-13.97" y="-8.89" drill="0.6" shape="square"/>
<pad name="A4" x="-13.97" y="-10.16" drill="0.6" shape="square"/>
<pad name="A5" x="-13.97" y="-11.43" drill="0.6" shape="square"/>
<pad name="RX" x="2.54" y="-11.43" drill="0.6" shape="square"/>
<pad name="TX" x="2.54" y="-10.16" drill="0.6" shape="square"/>
<pad name="D2" x="2.54" y="-8.89" drill="0.6" shape="square"/>
<pad name="D3" x="2.54" y="-7.62" drill="0.6" shape="square"/>
<pad name="D4" x="2.54" y="-6.35" drill="0.6" shape="square"/>
<pad name="D6" x="2.54" y="-3.81" drill="0.6" shape="square"/>
<pad name="D5" x="2.54" y="-5.08" drill="0.6" shape="square"/>
<pad name="D7" x="2.54" y="-2.54" drill="0.6" shape="square"/>
<pad name="D8" x="2.54" y="0" drill="0.6" shape="square"/>
<pad name="D9" x="2.54" y="1.27" drill="0.6" shape="square"/>
<pad name="D10" x="2.54" y="2.54" drill="0.6" shape="square"/>
<pad name="D11" x="2.54" y="3.81" drill="0.6" shape="square"/>
<pad name="D12" x="2.54" y="5.08" drill="0.6" shape="square"/>
<pad name="D13" x="2.54" y="6.35" drill="0.6" shape="square"/>
<pad name="GND2" x="2.54" y="7.62" drill="0.6" shape="square"/>
<pad name="AREF" x="2.54" y="8.89" drill="0.6" shape="square"/>
<pad name="SDA" x="2.54" y="10.16" drill="0.6" shape="square"/>
<pad name="SCL" x="2.54" y="11.43" drill="0.6" shape="square"/>
</package>
<package name="HC-06">
<pad name="VCC" x="-12.7" y="5.08" drill="0.6" shape="square"/>
<pad name="GND" x="-12.7" y="3.81" drill="0.6" shape="square"/>
<pad name="TX" x="-12.7" y="2.54" drill="0.6" shape="square"/>
<pad name="RX" x="-12.7" y="1.27" drill="0.6" shape="square"/>
<wire x1="-13.97" y1="6.35" x2="-3.81" y2="6.35" width="0.127" layer="21"/>
<wire x1="-3.81" y1="6.35" x2="-3.81" y2="0" width="0.127" layer="21"/>
<wire x1="-3.81" y1="0" x2="-13.97" y2="0" width="0.127" layer="21"/>
<wire x1="-13.97" y1="0" x2="-13.97" y2="6.35" width="0.127" layer="21"/>
</package>
<package name="L298N">
<pad name="OUT1" x="-11.43" y="2.54" drill="0.6" shape="square"/>
<pad name="OUT2" x="-11.43" y="1.27" drill="0.6" shape="square"/>
<pad name="12V" x="-10.16" y="-1.27" drill="0.6" shape="square"/>
<pad name="GND" x="-8.89" y="-1.27" drill="0.6" shape="square"/>
<pad name="5V" x="-7.62" y="-1.27" drill="0.6" shape="square"/>
<pad name="IN1" x="-3.81" y="-1.27" drill="0.6" shape="square"/>
<pad name="IN2" x="-2.54" y="-1.27" drill="0.6" shape="square"/>
<pad name="IN3" x="-1.27" y="-1.27" drill="0.6" shape="square"/>
<pad name="IN4" x="0" y="-1.27" drill="0.6" shape="square"/>
<pad name="OUT4" x="1.27" y="2.54" drill="0.6" shape="square"/>
<pad name="OUT3" x="1.27" y="1.27" drill="0.6" shape="square"/>
<wire x1="-12.7" y1="-2.54" x2="-12.7" y2="6.35" width="0.127" layer="21"/>
<wire x1="-12.7" y1="6.35" x2="2.54" y2="6.35" width="0.127" layer="21"/>
<wire x1="2.54" y1="6.35" x2="2.54" y2="-2.54" width="0.127" layer="21"/>
<wire x1="2.54" y1="-2.54" x2="-12.7" y2="-2.54" width="0.127" layer="21"/>
</package>
<package name="TP4056">
<pad name="OUT-" x="-8.89" y="5.08" drill="0.6" shape="square"/>
<pad name="B-" x="-8.89" y="3.81" drill="0.6" shape="square"/>
<pad name="B+" x="-8.89" y="1.27" drill="0.6" shape="square"/>
<pad name="OUT+" x="-8.89" y="0" drill="0.6" shape="square"/>
<pad name="-5V" x="0" y="5.08" drill="0.6" shape="square"/>
<pad name="+5V" x="0" y="0" drill="0.6" shape="square"/>
</package>
</packages>
<symbols>
<symbol name="ARDUINOUNO">
<pin name="NC" x="-43.18" y="20.32" length="middle"/>
<pin name="IOREF" x="-43.18" y="17.78" length="middle"/>
<pin name="REF" x="-43.18" y="15.24" length="middle"/>
<pin name="3.3V" x="-43.18" y="12.7" length="middle"/>
<pin name="5V" x="-43.18" y="10.16" length="middle"/>
<pin name="GND" x="-43.18" y="7.62" length="middle"/>
<pin name="GND1" x="-43.18" y="5.08" length="middle"/>
<pin name="VIN" x="-43.18" y="2.54" length="middle"/>
<pin name="A0" x="-43.18" y="-2.54" length="middle"/>
<pin name="A1" x="-43.18" y="-5.08" length="middle"/>
<pin name="A2" x="-43.18" y="-7.62" length="middle"/>
<pin name="A3" x="-43.18" y="-10.16" length="middle"/>
<pin name="A4" x="-43.18" y="-12.7" length="middle"/>
<pin name="A5" x="-43.18" y="-15.24" length="middle"/>
<pin name="RX" x="10.16" y="-15.24" length="middle" rot="R180"/>
<pin name="TX" x="10.16" y="-12.7" length="middle" rot="R180"/>
<pin name="D2" x="10.16" y="-10.16" length="middle" rot="R180"/>
<pin name="D3" x="10.16" y="-7.62" length="middle" rot="R180"/>
<pin name="D4" x="10.16" y="-5.08" length="middle" rot="R180"/>
<pin name="D5" x="10.16" y="-2.54" length="middle" rot="R180"/>
<pin name="D6" x="10.16" y="0" length="middle" rot="R180"/>
<pin name="D7" x="10.16" y="2.54" length="middle" rot="R180"/>
<pin name="D8" x="10.16" y="7.62" length="middle" rot="R180"/>
<pin name="D9" x="10.16" y="10.16" length="middle" rot="R180"/>
<pin name="D10" x="10.16" y="12.7" length="middle" rot="R180"/>
<pin name="D11" x="10.16" y="15.24" length="middle" rot="R180"/>
<pin name="D12" x="10.16" y="17.78" length="middle" rot="R180"/>
<pin name="D13" x="10.16" y="20.32" length="middle" rot="R180"/>
<pin name="GND2" x="10.16" y="22.86" length="middle" rot="R180"/>
<pin name="AREF" x="10.16" y="25.4" length="middle" rot="R180"/>
<pin name="SDA" x="10.16" y="27.94" length="middle" rot="R180"/>
<pin name="SCL" x="10.16" y="30.48" length="middle" rot="R180"/>
<text x="-12.7" y="-12.7" size="2.1844" layer="94" rot="R90">ARDUINO UNO</text>
<rectangle x1="-25.4" y1="-15.24" x2="-17.78" y2="10.16" layer="94"/>
<wire x1="-38.1" y1="-17.78" x2="-33.02" y2="-22.86" width="0.254" layer="94"/>
<wire x1="-33.02" y1="-22.86" x2="-5.08" y2="-22.86" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-22.86" x2="0" y2="-17.78" width="0.254" layer="94"/>
<wire x1="0" y1="-17.78" x2="5.08" y2="-17.78" width="0.254" layer="94"/>
<wire x1="5.08" y1="-17.78" x2="5.08" y2="43.18" width="0.254" layer="94"/>
<wire x1="5.08" y1="43.18" x2="-38.1" y2="43.18" width="0.254" layer="94"/>
<wire x1="-38.1" y1="43.18" x2="-38.1" y2="-17.78" width="0.254" layer="94"/>
<rectangle x1="-12.7" y1="33.02" x2="0" y2="48.26" layer="94"/>
</symbol>
<symbol name="HC-06">
<pin name="VCC" x="-33.02" y="10.16" length="middle"/>
<pin name="GND" x="-33.02" y="7.62" length="middle"/>
<pin name="TX" x="-33.02" y="5.08" length="middle"/>
<pin name="RX" x="-33.02" y="2.54" length="middle"/>
<wire x1="-27.94" y1="12.7" x2="-27.94" y2="0" width="0.254" layer="94"/>
<wire x1="-27.94" y1="0" x2="-2.54" y2="0" width="0.254" layer="94"/>
<wire x1="-2.54" y1="0" x2="-2.54" y2="12.7" width="0.254" layer="94"/>
<wire x1="-2.54" y1="12.7" x2="-27.94" y2="12.7" width="0.254" layer="94"/>
<text x="-20.32" y="5.08" size="2.54" layer="94">HC-06</text>
</symbol>
<symbol name="L298N">
<pin name="OUT1" x="-45.72" y="12.7" length="middle"/>
<pin name="OUT2" x="-45.72" y="10.16" length="middle"/>
<pin name="OUT3" x="-5.08" y="10.16" length="middle" rot="R180"/>
<pin name="OUT4" x="-5.08" y="12.7" length="middle" rot="R180"/>
<wire x1="-43.18" y1="2.54" x2="-7.62" y2="2.54" width="0.254" layer="94"/>
<wire x1="-7.62" y1="2.54" x2="-7.62" y2="25.4" width="0.254" layer="94"/>
<wire x1="-7.62" y1="25.4" x2="-43.18" y2="25.4" width="0.254" layer="94"/>
<wire x1="-43.18" y1="25.4" x2="-43.18" y2="2.54" width="0.254" layer="94"/>
<text x="-30.48" y="7.62" size="2.54" layer="94">L298N</text>
<rectangle x1="-38.1" y1="15.24" x2="-12.7" y2="22.86" layer="94"/>
<pin name="12V" x="-35.56" y="-2.54" length="middle" rot="R90"/>
<pin name="GND" x="-33.02" y="-2.54" length="middle" rot="R90"/>
<pin name="5V" x="-30.48" y="-2.54" length="middle" rot="R90"/>
<pin name="IN1" x="-20.32" y="-2.54" length="middle" rot="R90"/>
<pin name="IN2" x="-17.78" y="-2.54" length="middle" rot="R90"/>
<pin name="IN3" x="-15.24" y="-2.54" length="middle" rot="R90"/>
<pin name="IN4" x="-12.7" y="-2.54" length="middle" rot="R90"/>
</symbol>
<symbol name="TP4056">
<pin name="-5V" x="-40.64" y="17.78" length="middle"/>
<pin name="OUT-" x="-33.02" y="0" length="middle" rot="R90"/>
<pin name="B-" x="-30.48" y="0" length="middle" rot="R90"/>
<pin name="B+" x="-22.86" y="0" length="middle" rot="R90"/>
<pin name="OUT+" x="-20.32" y="0" length="middle" rot="R90"/>
<pin name="+5V" x="-12.7" y="17.78" length="middle" rot="R180"/>
<wire x1="-35.56" y1="22.86" x2="-35.56" y2="5.08" width="0.254" layer="94"/>
<wire x1="-35.56" y1="5.08" x2="-17.78" y2="5.08" width="0.254" layer="94"/>
<wire x1="-17.78" y1="5.08" x2="-17.78" y2="22.86" width="0.254" layer="94"/>
<wire x1="-17.78" y1="22.86" x2="-35.56" y2="22.86" width="0.254" layer="94"/>
<text x="-30.48" y="12.7" size="1.27" layer="94">TP4056</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="ARDUINOUNO">
<gates>
<gate name="G$1" symbol="ARDUINOUNO" x="-2.54" y="-5.08"/>
</gates>
<devices>
<device name="" package="ARDUINOUNO">
<connects>
<connect gate="G$1" pin="3.3V" pad="3.3V"/>
<connect gate="G$1" pin="5V" pad="5V"/>
<connect gate="G$1" pin="A0" pad="A0"/>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="A2" pad="A2"/>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="A4" pad="A4"/>
<connect gate="G$1" pin="A5" pad="A5"/>
<connect gate="G$1" pin="AREF" pad="AREF"/>
<connect gate="G$1" pin="D10" pad="D10"/>
<connect gate="G$1" pin="D11" pad="D11"/>
<connect gate="G$1" pin="D12" pad="D12"/>
<connect gate="G$1" pin="D13" pad="D13"/>
<connect gate="G$1" pin="D2" pad="D2"/>
<connect gate="G$1" pin="D3" pad="D3"/>
<connect gate="G$1" pin="D4" pad="D4"/>
<connect gate="G$1" pin="D5" pad="D5"/>
<connect gate="G$1" pin="D6" pad="D6"/>
<connect gate="G$1" pin="D7" pad="D7"/>
<connect gate="G$1" pin="D8" pad="D8"/>
<connect gate="G$1" pin="D9" pad="D9"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="GND1" pad="GND1"/>
<connect gate="G$1" pin="GND2" pad="GND2"/>
<connect gate="G$1" pin="IOREF" pad="IOREF"/>
<connect gate="G$1" pin="NC" pad="NC"/>
<connect gate="G$1" pin="REF" pad="RES"/>
<connect gate="G$1" pin="RX" pad="RX"/>
<connect gate="G$1" pin="SCL" pad="SCL"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
<connect gate="G$1" pin="TX" pad="TX"/>
<connect gate="G$1" pin="VIN" pad="VIN"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="HC-06">
<gates>
<gate name="G$1" symbol="HC-06" x="15.24" y="7.62"/>
</gates>
<devices>
<device name="" package="HC-06">
<connects>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="RX" pad="RX"/>
<connect gate="G$1" pin="TX" pad="TX"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="L298N">
<gates>
<gate name="G$1" symbol="L298N" x="22.86" y="5.08"/>
</gates>
<devices>
<device name="" package="L298N">
<connects>
<connect gate="G$1" pin="12V" pad="12V"/>
<connect gate="G$1" pin="5V" pad="5V"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="IN1" pad="IN1"/>
<connect gate="G$1" pin="IN2" pad="IN2"/>
<connect gate="G$1" pin="IN3" pad="IN3"/>
<connect gate="G$1" pin="IN4" pad="IN4"/>
<connect gate="G$1" pin="OUT1" pad="OUT1"/>
<connect gate="G$1" pin="OUT2" pad="OUT2"/>
<connect gate="G$1" pin="OUT3" pad="OUT3"/>
<connect gate="G$1" pin="OUT4" pad="OUT4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="TP4086">
<gates>
<gate name="G$1" symbol="TP4056" x="20.32" y="-2.54"/>
</gates>
<devices>
<device name="" package="TP4056">
<connects>
<connect gate="G$1" pin="+5V" pad="+5V"/>
<connect gate="G$1" pin="-5V" pad="-5V"/>
<connect gate="G$1" pin="B+" pad="B+"/>
<connect gate="G$1" pin="B-" pad="B-"/>
<connect gate="G$1" pin="OUT+" pad="OUT+"/>
<connect gate="G$1" pin="OUT-" pad="OUT-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="diode" urn="urn:adsk.eagle:library:210">
<description>&lt;b&gt;Diodes&lt;/b&gt;&lt;p&gt;
Based on the following sources:
&lt;ul&gt;
&lt;li&gt;Motorola : www.onsemi.com
&lt;li&gt;Fairchild : www.fairchildsemi.com
&lt;li&gt;Philips : www.semiconductors.com
&lt;li&gt;Vishay : www.vishay.de
&lt;/ul&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="DO41-10" urn="urn:adsk.eagle:footprint:43094/1" library_version="8">
<description>&lt;B&gt;DIODE&lt;/B&gt;&lt;p&gt;
diameter 2.54 mm, horizontal, grid 10.16 mm</description>
<wire x1="2.032" y1="-1.27" x2="-2.032" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.032" y1="-1.27" x2="2.032" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-2.032" y1="1.27" x2="2.032" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-2.032" y1="1.27" x2="-2.032" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0" x2="4.064" y2="0" width="0.762" layer="51"/>
<wire x1="-5.08" y1="0" x2="-4.064" y2="0" width="0.762" layer="51"/>
<wire x1="-0.635" y1="0" x2="0" y2="0" width="0.1524" layer="21"/>
<wire x1="1.016" y1="0.635" x2="1.016" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="1.016" y1="-0.635" x2="0" y2="0" width="0.1524" layer="21"/>
<wire x1="0" y1="0" x2="1.524" y2="0" width="0.1524" layer="21"/>
<wire x1="0" y1="0" x2="1.016" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0" y2="0" width="0.1524" layer="21"/>
<wire x1="0" y1="0" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<pad name="A" x="5.08" y="0" drill="1.1176"/>
<pad name="C" x="-5.08" y="0" drill="1.1176"/>
<text x="-2.032" y="1.651" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-2.032" y="-2.794" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="-1.651" y1="-1.27" x2="-1.143" y2="1.27" layer="21"/>
<rectangle x1="2.032" y1="-0.381" x2="3.937" y2="0.381" layer="21"/>
<rectangle x1="-3.937" y1="-0.381" x2="-2.032" y2="0.381" layer="21"/>
</package>
</packages>
<packages3d>
<package3d name="DO41-10" urn="urn:adsk.eagle:package:43336/1" type="box" library_version="8">
<description>DIODE
diameter 2.54 mm, horizontal, grid 10.16 mm</description>
<packageinstances>
<packageinstance name="DO41-10"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="D" urn="urn:adsk.eagle:symbol:43091/2" library_version="8">
<wire x1="-1.27" y1="-1.27" x2="1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="-1.27" y2="1.27" width="0.254" layer="94"/>
<wire x1="1.27" y1="1.27" x2="1.27" y2="0" width="0.254" layer="94"/>
<wire x1="-1.27" y1="1.27" x2="-1.27" y2="0" width="0.254" layer="94"/>
<wire x1="-1.27" y1="0" x2="-1.27" y2="-1.27" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="1.27" y2="-1.27" width="0.254" layer="94"/>
<wire x1="-1.27" y1="0" x2="-2.54" y2="0" width="0.254" layer="94"/>
<wire x1="2.54" y1="0" x2="1.27" y2="0" width="0.254" layer="94"/>
<text x="2.54" y="0.4826" size="1.778" layer="95">&gt;NAME</text>
<text x="2.54" y="-2.3114" size="1.778" layer="96">&gt;VALUE</text>
<text x="-2.54" y="0" size="0.4064" layer="99" align="center">SpiceOrder 1</text>
<text x="2.54" y="0" size="0.4064" layer="99" align="center">SpiceOrder 2</text>
<pin name="A" x="-2.54" y="0" visible="off" length="point" direction="pas"/>
<pin name="C" x="2.54" y="0" visible="off" length="point" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="1N4004" urn="urn:adsk.eagle:component:43462/3" prefix="D" library_version="8">
<description>&lt;B&gt;DIODE&lt;/B&gt;&lt;p&gt;
general purpose rectifier, 1 A</description>
<gates>
<gate name="1" symbol="D" x="0" y="0"/>
</gates>
<devices>
<device name="" package="DO41-10">
<connects>
<connect gate="1" pin="A" pad="A"/>
<connect gate="1" pin="C" pad="C"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:43336/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="82" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="battery" urn="urn:adsk.eagle:library:109">
<description>&lt;b&gt;Lithium Batteries and NC Accus&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="CRAA" urn="urn:adsk.eagle:footprint:4527/1" library_version="3">
<description>&lt;b&gt;LI BATTERY&lt;/b&gt; Varta</description>
<wire x1="23.622" y1="-7.493" x2="-25.146" y2="-7.493" width="0.1524" layer="21"/>
<wire x1="-25.146" y1="6.985" x2="-25.146" y2="7.493" width="0.1524" layer="21"/>
<wire x1="-25.4" y1="-3.175" x2="-25.4" y2="3.175" width="0.4064" layer="21"/>
<wire x1="-25.146" y1="-7.493" x2="-25.146" y2="-6.985" width="0.1524" layer="21"/>
<wire x1="25.4" y1="-2.413" x2="25.4" y2="2.413" width="0.4064" layer="51"/>
<wire x1="-25.4" y1="-6.985" x2="-25.4" y2="-3.175" width="0.1524" layer="51"/>
<wire x1="-25.4" y1="3.175" x2="-25.4" y2="6.985" width="0.4064" layer="51"/>
<wire x1="25.146" y1="1.778" x2="25.146" y2="3.556" width="0.1524" layer="21"/>
<wire x1="25.146" y1="-3.556" x2="25.146" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="25.146" y1="3.556" x2="24.257" y2="3.556" width="0.1524" layer="21"/>
<wire x1="24.257" y1="3.556" x2="24.257" y2="6.858" width="0.1524" layer="21"/>
<wire x1="25.146" y1="-3.556" x2="24.257" y2="-3.556" width="0.1524" layer="21"/>
<wire x1="24.257" y1="-3.556" x2="24.257" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="24.257" y1="-1.27" x2="24.257" y2="1.27" width="0.1524" layer="51"/>
<wire x1="24.257" y1="1.27" x2="24.257" y2="3.556" width="0.1524" layer="21"/>
<wire x1="-24.384" y1="0" x2="-22.86" y2="0" width="0.254" layer="21"/>
<wire x1="-23.622" y1="-0.762" x2="-23.622" y2="0.762" width="0.254" layer="21"/>
<wire x1="20.447" y1="0" x2="21.971" y2="0" width="0.1524" layer="21"/>
<wire x1="23.622" y1="-7.493" x2="24.257" y2="-6.858" width="0.1524" layer="21" curve="90"/>
<wire x1="23.622" y1="7.493" x2="24.257" y2="6.858" width="0.1524" layer="21" curve="-90"/>
<wire x1="24.257" y1="-6.858" x2="24.257" y2="-3.556" width="0.1524" layer="21"/>
<wire x1="23.622" y1="7.493" x2="-25.146" y2="7.493" width="0.1524" layer="21"/>
<wire x1="-2.921" y1="-2.54" x2="-2.921" y2="0" width="0.254" layer="21"/>
<wire x1="0.254" y1="0" x2="-1.651" y2="0" width="0.1524" layer="21"/>
<wire x1="-2.921" y1="0" x2="-5.207" y2="0" width="0.1524" layer="21"/>
<wire x1="-2.921" y1="0" x2="-2.921" y2="2.54" width="0.254" layer="21"/>
<wire x1="-3.429" y1="-1.524" x2="-4.445" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-3.937" y1="-2.032" x2="-3.937" y2="-1.016" width="0.1524" layer="21"/>
<pad name="+" x="-25.4" y="-5.08" drill="1.3208" diameter="3.1496" shape="octagon"/>
<pad name="+@1" x="-25.4" y="5.08" drill="1.3208" diameter="3.1496" shape="octagon"/>
<pad name="-" x="25.4" y="0" drill="1.3208" diameter="3.1496" shape="octagon"/>
<text x="-25.4" y="8.255" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-10.16" y="-5.08" size="1.27" layer="21" ratio="10">Lithium 3V</text>
<text x="17.018" y="-6.731" size="1.27" layer="21" ratio="10">CR-AA</text>
<text x="-7.62" y="3.81" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="-2.286" y1="-1.27" x2="-1.651" y2="1.27" layer="21"/>
</package>
</packages>
<packages3d>
<package3d name="CRAA" urn="urn:adsk.eagle:package:4582/2" type="model" library_version="3">
<description>LI BATTERY Varta</description>
<packageinstances>
<packageinstance name="CRAA"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="1V2+2" urn="urn:adsk.eagle:symbol:4517/1" library_version="3">
<wire x1="-1.905" y1="0.635" x2="-1.905" y2="0" width="0.4064" layer="94"/>
<wire x1="-2.54" y1="0" x2="-1.905" y2="0" width="0.1524" layer="94"/>
<wire x1="-1.905" y1="0" x2="-1.905" y2="-0.635" width="0.4064" layer="94"/>
<wire x1="-0.635" y1="2.54" x2="-0.635" y2="0" width="0.4064" layer="94"/>
<wire x1="-0.635" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="-0.635" y1="0" x2="-0.635" y2="-2.54" width="0.4064" layer="94"/>
<text x="-2.54" y="3.175" size="1.778" layer="95">&gt;NAME</text>
<text x="-2.54" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<pin name="+" x="5.08" y="0" visible="pad" length="short" direction="pas" rot="R180"/>
<pin name="-" x="-5.08" y="0" visible="pad" length="short" direction="pas"/>
<pin name="+@1" x="2.54" y="0" visible="off" length="point" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="CRAA" urn="urn:adsk.eagle:component:4625/3" prefix="G" library_version="3">
<description>&lt;b&gt;LI BATTERY&lt;/b&gt; Varta</description>
<gates>
<gate name="G$1" symbol="1V2+2" x="0" y="0"/>
</gates>
<devices>
<device name="" package="CRAA">
<connects>
<connect gate="G$1" pin="+" pad="+"/>
<connect gate="G$1" pin="+@1" pad="+@1"/>
<connect gate="G$1" pin="-" pad="-"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:4582/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="docu-dummy" urn="urn:adsk.eagle:library:215">
<description>Dummy symbols</description>
<packages>
</packages>
<symbols>
<symbol name="RESISTOR" urn="urn:adsk.eagle:symbol:13162/1" library_version="3">
<wire x1="-2.54" y1="-0.889" x2="2.54" y2="-0.889" width="0.254" layer="94"/>
<wire x1="2.54" y1="0.889" x2="-2.54" y2="0.889" width="0.254" layer="94"/>
<wire x1="2.54" y1="-0.889" x2="2.54" y2="0" width="0.254" layer="94"/>
<wire x1="2.54" y1="0" x2="2.54" y2="0.889" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-0.889" x2="-2.54" y2="0" width="0.254" layer="94"/>
<wire x1="-2.54" y1="0" x2="-2.54" y2="0.889" width="0.254" layer="94"/>
<wire x1="-5.08" y1="0" x2="-2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="2.54" y1="0" x2="5.08" y2="0" width="0.1524" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="R" urn="urn:adsk.eagle:component:13171/1" prefix="R" library_version="3">
<description>&lt;b&gt;RESISTOR&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="RESISTOR" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="led" urn="urn:adsk.eagle:library:259">
<description>&lt;b&gt;LEDs&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;&lt;br&gt;
Extended by Federico Battaglin &lt;author&gt;&amp;lt;federico.rd@fdpinternational.com&amp;gt;&lt;/author&gt; with DUOLED</description>
<packages>
<package name="W57B" urn="urn:adsk.eagle:footprint:15733/1" library_version="5">
<description>&lt;b&gt;Golden Dragon® 1 Watt LED&lt;/b&gt;&lt;p&gt;
Source: OSRAM la_ly_w57b.pdf</description>
<wire x1="-3.475" y1="1.8" x2="-2.275" y2="3" width="0.2032" layer="21" curve="-90"/>
<wire x1="-2.275" y1="3" x2="2.3" y2="3" width="0.2032" layer="21"/>
<wire x1="2.3" y1="3" x2="3.5" y2="1.8" width="0.2032" layer="21" curve="-90"/>
<wire x1="3.5" y1="1.8" x2="3.5" y2="-1.8" width="0.2032" layer="21"/>
<wire x1="3.5" y1="-1.8" x2="2.3" y2="-3" width="0.2032" layer="21" curve="-90"/>
<wire x1="2.3" y1="-3" x2="-2.275" y2="-3" width="0.2032" layer="21"/>
<wire x1="-2.275" y1="-3" x2="-3.475" y2="-1.8" width="0.2032" layer="21" curve="-90"/>
<wire x1="-3.475" y1="-1.8" x2="-3.475" y2="1.8" width="0.2032" layer="21"/>
<wire x1="-1.1808" y1="0.6799" x2="-1.6638" y2="0.6799" width="0.1016" layer="51"/>
<wire x1="-1.6638" y1="0.6799" x2="-2.3437" y2="0" width="0.1016" layer="51" curve="90"/>
<wire x1="-2.3437" y1="0" x2="-1.646" y2="-0.6977" width="0.1016" layer="51" curve="90"/>
<wire x1="-1.646" y1="-0.6977" x2="-1.1808" y2="-0.6977" width="0.1016" layer="51"/>
<wire x1="-1.1808" y1="-0.6977" x2="-1.0019" y2="-0.3936" width="0.1016" layer="51"/>
<wire x1="-1.0019" y1="-0.3936" x2="-1.0019" y2="0.4115" width="0.1016" layer="51" curve="-50.166839"/>
<wire x1="-1.0019" y1="0.4115" x2="-1.1808" y2="0.6799" width="0.1016" layer="51"/>
<wire x1="-1.0377" y1="0.4473" x2="-1.6281" y2="0.4473" width="0.1016" layer="51"/>
<wire x1="-1.6281" y1="0.4473" x2="-2.0754" y2="0" width="0.1016" layer="51" curve="90"/>
<wire x1="-2.0754" y1="0" x2="-1.6281" y2="-0.4473" width="0.1016" layer="51" curve="90"/>
<wire x1="-1.6281" y1="-0.4473" x2="-1.0556" y2="-0.4473" width="0.1016" layer="51"/>
<wire x1="-1.1271" y1="0.7156" x2="-1.1271" y2="-0.7156" width="0.1016" layer="51" curve="-295.788054"/>
<circle x="0" y="0" radius="0.8947" width="0.1016" layer="51"/>
<circle x="1.3239" y="1.3597" radius="0.3225" width="0.1016" layer="51"/>
<circle x="0" y="0" radius="2" width="0" layer="29"/>
<circle x="0" y="0" radius="1.7751" width="0" layer="31"/>
<smd name="A" x="-5.7" y="0" dx="3" dy="3" layer="1" stop="no"/>
<smd name="C" x="5.7" y="0" dx="3" dy="3" layer="1" stop="no"/>
<smd name="C@1" x="3.75" y="3.375" dx="7.5" dy="3.2" layer="1" stop="no" cream="no"/>
<smd name="C@2" x="-3.75" y="3.375" dx="7.5" dy="3.2" layer="1" stop="no" cream="no"/>
<smd name="C@3" x="-3.75" y="-3.4" dx="7.5" dy="3.2" layer="1" stop="no" cream="no"/>
<smd name="C@4" x="3.75" y="-3.4" dx="7.5" dy="3.2" layer="1" stop="no" cream="no"/>
<smd name="C@5" x="0" y="0" dx="7.8" dy="4" layer="1" stop="no" cream="no"/>
<text x="-2.54" y="3.81" size="1.27" layer="25">&gt;NAME</text>
<text x="-3.175" y="-4.445" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-0.25" y1="-0.25" x2="0.25" y2="0.25" layer="51"/>
<rectangle x1="-5.575" y1="-1" x2="-3.55" y2="1" layer="51"/>
<rectangle x1="3.55" y1="-1" x2="5.575" y2="1" layer="51" rot="R180"/>
<rectangle x1="-7.375" y1="-1.675" x2="-4.025" y2="1.675" layer="29"/>
<rectangle x1="4.025" y1="-1.675" x2="7.375" y2="1.675" layer="29"/>
</package>
</packages>
<packages3d>
<package3d name="W57B" urn="urn:adsk.eagle:package:15859/1" type="box" library_version="5">
<description>Golden Dragon® 1 Watt LED
Source: OSRAM la_ly_w57b.pdf</description>
<packageinstances>
<packageinstance name="W57B"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="LED" urn="urn:adsk.eagle:symbol:15639/2" library_version="5">
<wire x1="1.27" y1="0" x2="0" y2="-2.54" width="0.254" layer="94"/>
<wire x1="0" y1="-2.54" x2="-1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="0" y2="-2.54" width="0.254" layer="94"/>
<wire x1="0" y1="-2.54" x2="-1.27" y2="-2.54" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="0" width="0.254" layer="94"/>
<wire x1="-2.032" y1="-0.762" x2="-3.429" y2="-2.159" width="0.1524" layer="94"/>
<wire x1="-1.905" y1="-1.905" x2="-3.302" y2="-3.302" width="0.1524" layer="94"/>
<text x="3.556" y="-4.572" size="1.778" layer="95" rot="R90">&gt;NAME</text>
<text x="5.715" y="-4.572" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="C" x="0" y="-5.08" visible="off" length="short" direction="pas" rot="R90"/>
<pin name="A" x="0" y="2.54" visible="off" length="short" direction="pas" rot="R270"/>
<polygon width="0.1524" layer="94">
<vertex x="-3.429" y="-2.159"/>
<vertex x="-3.048" y="-1.27"/>
<vertex x="-2.54" y="-1.778"/>
</polygon>
<polygon width="0.1524" layer="94">
<vertex x="-3.302" y="-3.302"/>
<vertex x="-2.921" y="-2.413"/>
<vertex x="-2.413" y="-2.921"/>
</polygon>
</symbol>
</symbols>
<devicesets>
<deviceset name="*W57B" urn="urn:adsk.eagle:component:15943/3" prefix="LED" library_version="5">
<description>&lt;b&gt;Golden Dragon® 1 Watt LED&lt;/b&gt;&lt;p&gt;
Place heat sink pads of cathode with INVOKE&lt;br&gt;
Source: www.osram-os.com la_ly_w57b.pdf</description>
<gates>
<gate name="G$1" symbol="LED" x="0" y="0"/>
</gates>
<devices>
<device name="" package="W57B">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="C C@1 C@2 C@3 C@4 C@5"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:15859/1"/>
</package3dinstances>
<technologies>
<technology name="LA">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
<technology name="LY">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="buzzer" urn="urn:adsk.eagle:library:113">
<description>&lt;b&gt;Speakers and Buzzers&lt;/b&gt;&lt;p&gt;
&lt;ul&gt;Distributors:
&lt;li&gt;Buerklin
&lt;li&gt;Spoerle
&lt;li&gt;Schukat
&lt;/ul&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="B/C11L" urn="urn:adsk.eagle:footprint:5241/1" library_version="2">
<description>&lt;b&gt;BUZZER&lt;/b&gt;</description>
<wire x1="-6.858" y1="8.001" x2="6.858" y2="8.001" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-8.001" x2="1.905" y2="-8.001" width="0.1524" layer="21"/>
<wire x1="-7.493" y1="-7.366" x2="-7.493" y2="7.366" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-8.255" x2="-4.191" y2="-8.001" width="0.1524" layer="51" curve="-90"/>
<wire x1="-4.445" y1="-8.636" x2="-4.191" y2="-8.89" width="0.1524" layer="51" curve="90"/>
<wire x1="-7.493" y1="-7.366" x2="-6.858" y2="-8.001" width="0.1524" layer="21" curve="90"/>
<wire x1="-5.715" y1="-8.001" x2="-5.715" y2="-8.255" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-8.255" x2="-5.461" y2="-8.509" width="0.1524" layer="21" curve="90"/>
<wire x1="-6.858" y1="-8.001" x2="-5.715" y2="-8.001" width="0.1524" layer="21"/>
<wire x1="-5.461" y1="-8.509" x2="-5.262" y2="-8.509" width="0.1524" layer="21"/>
<wire x1="-4.699" y1="-8.509" x2="-4.445" y2="-8.255" width="0.1524" layer="51" curve="90"/>
<wire x1="-4.445" y1="-8.636" x2="-4.445" y2="-8.255" width="0.1524" layer="51"/>
<wire x1="-5.262" y1="-8.509" x2="-4.699" y2="-8.509" width="0.1524" layer="51"/>
<wire x1="-1.905" y1="-8.255" x2="-1.905" y2="-8.001" width="0.1524" layer="21"/>
<wire x1="-2.159" y1="-8.509" x2="-1.905" y2="-8.255" width="0.1524" layer="21" curve="90"/>
<wire x1="-2.257" y1="-8.509" x2="-2.159" y2="-8.509" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-8.255" x2="-2.921" y2="-8.509" width="0.1524" layer="51" curve="90"/>
<wire x1="-3.429" y1="-8.001" x2="-3.175" y2="-8.255" width="0.1524" layer="51" curve="-90"/>
<wire x1="-4.191" y1="-8.89" x2="-3.429" y2="-8.89" width="0.1524" layer="51"/>
<wire x1="-3.175" y1="-8.636" x2="-3.175" y2="-8.255" width="0.1524" layer="51"/>
<wire x1="-3.429" y1="-8.89" x2="-3.175" y2="-8.636" width="0.1524" layer="51" curve="90"/>
<wire x1="-4.191" y1="-8.001" x2="-3.429" y2="-8.001" width="0.1524" layer="51"/>
<wire x1="-2.921" y1="-8.509" x2="-2.257" y2="-8.509" width="0.1524" layer="51"/>
<wire x1="-7.493" y1="7.366" x2="-6.858" y2="8.001" width="0.1524" layer="21" curve="-90"/>
<wire x1="7.493" y1="-7.366" x2="7.493" y2="7.366" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-8.001" x2="6.858" y2="-8.001" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-8.001" x2="5.715" y2="-8.255" width="0.1524" layer="21"/>
<wire x1="5.461" y1="-8.509" x2="5.715" y2="-8.255" width="0.1524" layer="21" curve="90"/>
<wire x1="1.905" y1="-8.255" x2="1.905" y2="-8.001" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-8.255" x2="2.159" y2="-8.509" width="0.1524" layer="21" curve="90"/>
<wire x1="2.257" y1="-8.509" x2="2.159" y2="-8.509" width="0.1524" layer="21"/>
<wire x1="5.461" y1="-8.509" x2="5.262" y2="-8.509" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-8.255" x2="4.699" y2="-8.509" width="0.1524" layer="51" curve="90"/>
<wire x1="2.921" y1="-8.509" x2="3.175" y2="-8.255" width="0.1524" layer="51" curve="90"/>
<wire x1="4.191" y1="-8.89" x2="4.445" y2="-8.636" width="0.1524" layer="51" curve="90"/>
<wire x1="4.445" y1="-8.255" x2="4.445" y2="-8.636" width="0.1524" layer="51"/>
<wire x1="4.191" y1="-8.001" x2="4.445" y2="-8.255" width="0.1524" layer="51" curve="-90"/>
<wire x1="3.429" y1="-8.001" x2="4.191" y2="-8.001" width="0.1524" layer="51"/>
<wire x1="3.175" y1="-8.255" x2="3.429" y2="-8.001" width="0.1524" layer="51" curve="-90"/>
<wire x1="3.175" y1="-8.636" x2="3.175" y2="-8.255" width="0.1524" layer="51"/>
<wire x1="3.429" y1="-8.89" x2="4.191" y2="-8.89" width="0.1524" layer="51"/>
<wire x1="3.175" y1="-8.636" x2="3.429" y2="-8.89" width="0.1524" layer="51" curve="90"/>
<wire x1="2.921" y1="-8.509" x2="2.257" y2="-8.509" width="0.1524" layer="51"/>
<wire x1="5.262" y1="-8.509" x2="4.699" y2="-8.509" width="0.1524" layer="51"/>
<wire x1="6.858" y1="-8.001" x2="7.493" y2="-7.366" width="0.1524" layer="21" curve="90"/>
<wire x1="6.858" y1="8.001" x2="7.493" y2="7.366" width="0.1524" layer="21" curve="-90"/>
<circle x="0" y="0" radius="5.08" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="1.27" width="0.1524" layer="21"/>
<pad name="1" x="-3.7592" y="-8.255" drill="1.3208" diameter="2.54" shape="octagon"/>
<pad name="2" x="3.7592" y="-8.255" drill="1.3208" diameter="2.54" shape="octagon"/>
<text x="-7.493" y="8.382" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-5.08" y="5.715" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
</packages>
<packages3d>
<package3d name="B/C11L" urn="urn:adsk.eagle:package:5280/1" type="box" library_version="2">
<description>BUZZER</description>
<packageinstances>
<packageinstance name="B/C11L"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="B2P" urn="urn:adsk.eagle:symbol:5221/1" library_version="2">
<wire x1="-1.27" y1="3.175" x2="0" y2="3.175" width="0.1524" layer="94"/>
<wire x1="0" y1="3.175" x2="0" y2="3.81" width="0.1524" layer="94"/>
<wire x1="0" y1="3.175" x2="0" y2="2.54" width="0.1524" layer="94"/>
<wire x1="0.635" y1="4.445" x2="0.635" y2="1.905" width="0.1524" layer="94"/>
<wire x1="0.635" y1="1.905" x2="1.905" y2="1.905" width="0.1524" layer="94"/>
<wire x1="1.905" y1="1.905" x2="1.905" y2="4.445" width="0.1524" layer="94"/>
<wire x1="1.905" y1="4.445" x2="0.635" y2="4.445" width="0.1524" layer="94"/>
<wire x1="2.54" y1="3.81" x2="2.54" y2="3.175" width="0.1524" layer="94"/>
<wire x1="2.54" y1="3.175" x2="3.81" y2="3.175" width="0.1524" layer="94"/>
<wire x1="2.54" y1="3.175" x2="2.54" y2="2.54" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="2.54" y2="1.27" width="0.1524" layer="94"/>
<wire x1="0" y1="-2.54" x2="0" y2="1.27" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="1.27" x2="0" y2="1.27" width="0.254" layer="94"/>
<wire x1="5.08" y1="1.27" x2="5.08" y2="5.08" width="0.254" layer="94"/>
<wire x1="5.08" y1="5.08" x2="5.715" y2="5.08" width="0.254" layer="94"/>
<wire x1="5.715" y1="5.08" x2="5.715" y2="5.715" width="0.254" layer="94"/>
<wire x1="5.715" y1="5.715" x2="-3.175" y2="5.715" width="0.254" layer="94"/>
<wire x1="-3.175" y1="5.715" x2="-3.175" y2="5.08" width="0.254" layer="94"/>
<wire x1="-3.175" y1="5.08" x2="-2.54" y2="5.08" width="0.254" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="-2.54" y2="1.27" width="0.254" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="5.08" y2="5.08" width="0.254" layer="94"/>
<wire x1="2.54" y1="1.27" x2="5.08" y2="1.27" width="0.254" layer="94"/>
<wire x1="0" y1="1.27" x2="2.54" y2="1.27" width="0.254" layer="94"/>
<text x="-2.54" y="6.35" size="1.778" layer="95">&gt;NAME</text>
<text x="6.35" y="0" size="1.778" layer="96">&gt;VALUE</text>
<pin name="2" x="5.08" y="-2.54" visible="pad" length="short" direction="pas" rot="R180"/>
<pin name="1" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="B/C11L" urn="urn:adsk.eagle:component:5319/2" prefix="SG" library_version="2">
<description>&lt;b&gt;BUZZER&lt;/b&gt;&lt;p&gt; Source: Buerklin</description>
<gates>
<gate name="G$1" symbol="B2P" x="0" y="0"/>
</gates>
<devices>
<device name="" package="B/C11L">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:5280/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
<attribute name="POPULARITY" value="2" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="ESP32 DEVKIT V1" deviceset="ARDUINOUNO" device=""/>
<part name="U$2" library="ESP32 DEVKIT V1" deviceset="HC-06" device=""/>
<part name="U$3" library="ESP32 DEVKIT V1" deviceset="L298N" device=""/>
<part name="U$4" library="ESP32 DEVKIT V1" deviceset="TP4086" device=""/>
<part name="U$5" library="ESP32 DEVKIT V1" deviceset="TP4086" device=""/>
<part name="U$6" library="ESP32 DEVKIT V1" deviceset="TP4086" device=""/>
<part name="D1" library="diode" library_urn="urn:adsk.eagle:library:210" deviceset="1N4004" device="" package3d_urn="urn:adsk.eagle:package:43336/1"/>
<part name="D2" library="diode" library_urn="urn:adsk.eagle:library:210" deviceset="1N4004" device="" package3d_urn="urn:adsk.eagle:package:43336/1"/>
<part name="B1" library="battery" library_urn="urn:adsk.eagle:library:109" deviceset="CRAA" device="" package3d_urn="urn:adsk.eagle:package:4582/2" value="3,7V"/>
<part name="B2" library="battery" library_urn="urn:adsk.eagle:library:109" deviceset="CRAA" device="" package3d_urn="urn:adsk.eagle:package:4582/2" value="3,7V"/>
<part name="B3" library="battery" library_urn="urn:adsk.eagle:library:109" deviceset="CRAA" device="" package3d_urn="urn:adsk.eagle:package:4582/2" value="3,7V"/>
<part name="MOTOR1" library="docu-dummy" library_urn="urn:adsk.eagle:library:215" deviceset="R" device=""/>
<part name="MOTOR2" library="docu-dummy" library_urn="urn:adsk.eagle:library:215" deviceset="R" device=""/>
<part name="R3" library="docu-dummy" library_urn="urn:adsk.eagle:library:215" deviceset="R" device=""/>
<part name="R4" library="docu-dummy" library_urn="urn:adsk.eagle:library:215" deviceset="R" device=""/>
<part name="LED1" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*W57B" device="" package3d_urn="urn:adsk.eagle:package:15859/1" technology="LA"/>
<part name="LED2" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*W57B" device="" package3d_urn="urn:adsk.eagle:package:15859/1" technology="LA"/>
<part name="LED3" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*W57B" device="" package3d_urn="urn:adsk.eagle:package:15859/1" technology="LA"/>
<part name="LEDPUTIH" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*W57B" device="" package3d_urn="urn:adsk.eagle:package:15859/1" technology="LA"/>
<part name="LEDMERAH" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*W57B" device="" package3d_urn="urn:adsk.eagle:package:15859/1" technology="LA"/>
<part name="BUZZER" library="buzzer" library_urn="urn:adsk.eagle:library:113" deviceset="B/C11L" device="" package3d_urn="urn:adsk.eagle:package:5280/1"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="-33.02" y="-60.96" smashed="yes" rot="R90"/>
<instance part="U$2" gate="G$1" x="27.94" y="-50.8" smashed="yes"/>
<instance part="U$3" gate="G$1" x="-38.1" y="-20.32" smashed="yes"/>
<instance part="U$4" gate="G$1" x="-157.48" y="-22.86" smashed="yes"/>
<instance part="U$5" gate="G$1" x="-124.46" y="-22.86" smashed="yes"/>
<instance part="U$6" gate="G$1" x="-91.44" y="-22.86" smashed="yes"/>
<instance part="D1" gate="1" x="-167.64" y="-30.48" smashed="yes">
<attribute name="NAME" x="-165.1" y="-29.9974" size="1.778" layer="95"/>
<attribute name="VALUE" x="-165.1" y="-32.7914" size="1.778" layer="96"/>
</instance>
<instance part="D2" gate="1" x="-132.08" y="-30.48" smashed="yes">
<attribute name="NAME" x="-129.54" y="-29.9974" size="1.778" layer="95"/>
<attribute name="VALUE" x="-129.54" y="-32.7914" size="1.778" layer="96"/>
</instance>
<instance part="B1" gate="G$1" x="-182.88" y="-40.64" smashed="yes">
<attribute name="NAME" x="-185.42" y="-37.465" size="1.778" layer="95"/>
<attribute name="VALUE" x="-185.42" y="-45.72" size="1.778" layer="96"/>
</instance>
<instance part="B2" gate="G$1" x="-149.86" y="-40.64" smashed="yes">
<attribute name="NAME" x="-152.4" y="-37.465" size="1.778" layer="95"/>
<attribute name="VALUE" x="-152.4" y="-45.72" size="1.778" layer="96"/>
</instance>
<instance part="B3" gate="G$1" x="-116.84" y="-40.64" smashed="yes">
<attribute name="NAME" x="-119.38" y="-37.465" size="1.778" layer="95"/>
<attribute name="VALUE" x="-119.38" y="-45.72" size="1.778" layer="96"/>
</instance>
<instance part="MOTOR1" gate="G$1" x="-93.98" y="-7.62" smashed="yes" rot="R90"/>
<instance part="MOTOR2" gate="G$1" x="-91.44" y="-7.62" smashed="yes" rot="R90"/>
<instance part="R3" gate="G$1" x="-33.02" y="-7.62" smashed="yes" rot="R90"/>
<instance part="R4" gate="G$1" x="-35.56" y="-7.62" smashed="yes" rot="R90"/>
<instance part="LED1" gate="G$1" x="5.08" y="-71.12" smashed="yes"/>
<instance part="LED2" gate="G$1" x="12.7" y="-71.12" smashed="yes"/>
<instance part="LED3" gate="G$1" x="20.32" y="-71.12" smashed="yes"/>
<instance part="LEDPUTIH" gate="G$1" x="27.94" y="-71.12" smashed="yes">
<attribute name="NAME" x="31.496" y="-75.692" size="1.778" layer="95" rot="R90"/>
</instance>
<instance part="LEDMERAH" gate="G$1" x="-2.54" y="-71.12" smashed="yes">
<attribute name="NAME" x="1.016" y="-75.692" size="1.778" layer="95" rot="R90"/>
</instance>
<instance part="BUZZER" gate="G$1" x="-12.7" y="-30.48" smashed="yes" rot="MR0">
<attribute name="NAME" x="-10.16" y="-24.13" size="1.778" layer="95" rot="MR0"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="+5V"/>
<pinref part="U$5" gate="G$1" pin="-5V"/>
<wire x1="-170.18" y1="-5.08" x2="-165.1" y2="-5.08" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="+5V"/>
<pinref part="U$6" gate="G$1" pin="-5V"/>
<wire x1="-137.16" y1="-5.08" x2="-132.08" y2="-5.08" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="D1" gate="1" pin="A"/>
<pinref part="U$4" gate="G$1" pin="OUT+"/>
<wire x1="-170.18" y1="-30.48" x2="-177.8" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="-177.8" y1="-30.48" x2="-177.8" y2="-22.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="D1" gate="1" pin="C"/>
<pinref part="U$5" gate="G$1" pin="OUT-"/>
<wire x1="-165.1" y1="-30.48" x2="-157.48" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="-157.48" y1="-30.48" x2="-157.48" y2="-22.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="D2" gate="1" pin="A"/>
<pinref part="U$5" gate="G$1" pin="OUT+"/>
<wire x1="-134.62" y1="-30.48" x2="-144.78" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="-144.78" y1="-30.48" x2="-144.78" y2="-22.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="D2" gate="1" pin="C"/>
<pinref part="U$6" gate="G$1" pin="OUT-"/>
<wire x1="-129.54" y1="-30.48" x2="-124.46" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="-124.46" y1="-30.48" x2="-124.46" y2="-22.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="B2" gate="G$1" pin="-"/>
<pinref part="U$5" gate="G$1" pin="B-"/>
<wire x1="-154.94" y1="-40.64" x2="-154.94" y2="-22.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="B+"/>
<wire x1="-147.32" y1="-22.86" x2="-147.32" y2="-38.1" width="0.1524" layer="91"/>
<pinref part="B2" gate="G$1" pin="+"/>
<wire x1="-144.78" y1="-40.64" x2="-144.78" y2="-38.1" width="0.1524" layer="91"/>
<wire x1="-144.78" y1="-38.1" x2="-147.32" y2="-38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="U$6" gate="G$1" pin="B-"/>
<pinref part="B3" gate="G$1" pin="-"/>
<wire x1="-121.92" y1="-22.86" x2="-121.92" y2="-40.64" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="U$6" gate="G$1" pin="B+"/>
<wire x1="-114.3" y1="-22.86" x2="-114.3" y2="-38.1" width="0.1524" layer="91"/>
<wire x1="-114.3" y1="-38.1" x2="-111.76" y2="-38.1" width="0.1524" layer="91"/>
<pinref part="B3" gate="G$1" pin="+"/>
<wire x1="-111.76" y1="-38.1" x2="-111.76" y2="-40.64" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="B+"/>
<wire x1="-180.34" y1="-22.86" x2="-180.34" y2="-38.1" width="0.1524" layer="91"/>
<wire x1="-180.34" y1="-38.1" x2="-177.8" y2="-38.1" width="0.1524" layer="91"/>
<pinref part="B1" gate="G$1" pin="+"/>
<wire x1="-177.8" y1="-38.1" x2="-177.8" y2="-40.64" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="B1" gate="G$1" pin="-"/>
<pinref part="U$4" gate="G$1" pin="B-"/>
<wire x1="-187.96" y1="-40.64" x2="-187.96" y2="-22.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="IN4"/>
<pinref part="U$1" gate="G$1" pin="D4"/>
<wire x1="-50.8" y1="-22.86" x2="-27.94" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="-27.94" y1="-22.86" x2="-27.94" y2="-50.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$16" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="IN3"/>
<wire x1="-53.34" y1="-22.86" x2="-53.34" y2="-25.4" width="0.1524" layer="91"/>
<wire x1="-53.34" y1="-25.4" x2="-30.48" y2="-25.4" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="D5"/>
<wire x1="-30.48" y1="-25.4" x2="-30.48" y2="-50.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="IN2"/>
<wire x1="-55.88" y1="-22.86" x2="-55.88" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="-55.88" y1="-27.94" x2="-33.02" y2="-27.94" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="D6"/>
<wire x1="-33.02" y1="-27.94" x2="-33.02" y2="-50.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$18" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D9"/>
<wire x1="-43.18" y1="-50.8" x2="-43.18" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="-43.18" y1="-30.48" x2="-58.42" y2="-30.48" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="IN1"/>
<wire x1="-58.42" y1="-30.48" x2="-58.42" y2="-22.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$19" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="OUT4"/>
<wire x1="-33.02" y1="-2.54" x2="-43.18" y2="-2.54" width="0.1524" layer="91"/>
<wire x1="-43.18" y1="-2.54" x2="-43.18" y2="-7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$20" class="0">
<segment>
<wire x1="-35.56" y1="-12.7" x2="-33.02" y2="-12.7" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="OUT3"/>
<wire x1="-35.56" y1="-12.7" x2="-43.18" y2="-12.7" width="0.1524" layer="91"/>
<wire x1="-43.18" y1="-12.7" x2="-43.18" y2="-10.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$21" class="0">
<segment>
<wire x1="-93.98" y1="-2.54" x2="-83.82" y2="-2.54" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="OUT1"/>
<wire x1="-83.82" y1="-2.54" x2="-83.82" y2="-7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$22" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="OUT2"/>
<wire x1="-93.98" y1="-12.7" x2="-83.82" y2="-12.7" width="0.1524" layer="91"/>
<wire x1="-83.82" y1="-12.7" x2="-83.82" y2="-10.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$23" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="TX"/>
<pinref part="U$1" gate="G$1" pin="RX"/>
<wire x1="-5.08" y1="-45.72" x2="-17.78" y2="-45.72" width="0.1524" layer="91"/>
<wire x1="-17.78" y1="-45.72" x2="-17.78" y2="-50.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$24" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="RX"/>
<pinref part="U$1" gate="G$1" pin="TX"/>
<wire x1="-5.08" y1="-48.26" x2="-20.32" y2="-48.26" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="-48.26" x2="-20.32" y2="-50.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="5V" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="VCC"/>
<wire x1="-5.08" y1="-40.64" x2="-12.7" y2="-40.64" width="0.1524" layer="91"/>
<label x="-12.7" y="-40.64" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="5V"/>
<wire x1="-43.18" y1="-104.14" x2="-43.18" y2="-111.76" width="0.1524" layer="91"/>
<wire x1="-43.18" y1="-111.76" x2="-33.02" y2="-111.76" width="0.1524" layer="91"/>
<label x="-40.64" y="-111.76" size="1.778" layer="95"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="LED1" gate="G$1" pin="A"/>
<wire x1="5.08" y1="-68.58" x2="5.08" y2="-66.04" width="0.1524" layer="91"/>
<pinref part="LED2" gate="G$1" pin="A"/>
<wire x1="5.08" y1="-66.04" x2="12.7" y2="-66.04" width="0.1524" layer="91"/>
<wire x1="12.7" y1="-66.04" x2="12.7" y2="-68.58" width="0.1524" layer="91"/>
<pinref part="LED3" gate="G$1" pin="A"/>
<wire x1="20.32" y1="-68.58" x2="20.32" y2="-66.04" width="0.1524" layer="91"/>
<wire x1="20.32" y1="-66.04" x2="12.7" y2="-66.04" width="0.1524" layer="91"/>
<junction x="12.7" y="-66.04"/>
<pinref part="LEDPUTIH" gate="G$1" pin="A"/>
<wire x1="27.94" y1="-68.58" x2="27.94" y2="-66.04" width="0.1524" layer="91"/>
<wire x1="27.94" y1="-66.04" x2="20.32" y2="-66.04" width="0.1524" layer="91"/>
<junction x="20.32" y="-66.04"/>
<pinref part="LEDMERAH" gate="G$1" pin="A"/>
<wire x1="-2.54" y1="-68.58" x2="-2.54" y2="-60.96" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="-60.96" x2="5.08" y2="-60.96" width="0.1524" layer="91"/>
<wire x1="5.08" y1="-60.96" x2="5.08" y2="-66.04" width="0.1524" layer="91"/>
<junction x="5.08" y="-66.04"/>
<wire x1="-2.54" y1="-60.96" x2="-7.62" y2="-60.96" width="0.1524" layer="91"/>
<junction x="-2.54" y="-60.96"/>
<label x="-7.62" y="-60.96" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$2" gate="G$1" pin="GND"/>
<wire x1="-5.08" y1="-43.18" x2="-12.7" y2="-43.18" width="0.1524" layer="91"/>
<label x="-12.7" y="-43.18" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="GND"/>
<wire x1="-40.64" y1="-104.14" x2="-40.64" y2="-109.22" width="0.1524" layer="91"/>
<wire x1="-40.64" y1="-109.22" x2="-33.02" y2="-109.22" width="0.1524" layer="91"/>
<label x="-38.1" y="-109.22" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$4" gate="G$1" pin="OUT-"/>
<wire x1="-190.5" y1="-22.86" x2="-190.5" y2="-53.34" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="GND"/>
<wire x1="-190.5" y1="-53.34" x2="-119.38" y2="-53.34" width="0.1524" layer="91"/>
<wire x1="-119.38" y1="-53.34" x2="-71.12" y2="-53.34" width="0.1524" layer="91"/>
<wire x1="-71.12" y1="-53.34" x2="-71.12" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="-119.38" y1="-53.34" x2="-119.38" y2="-58.42" width="0.1524" layer="91"/>
<wire x1="-119.38" y1="-58.42" x2="-114.3" y2="-58.42" width="0.1524" layer="91"/>
<label x="-119.38" y="-58.42" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="BUZZER" gate="G$1" pin="1"/>
<wire x1="-10.16" y1="-33.02" x2="-2.54" y2="-33.02" width="0.1524" layer="91"/>
<label x="-7.62" y="-33.02" size="1.778" layer="95"/>
</segment>
</net>
<net name="A4" class="0">
<segment>
<pinref part="LED1" gate="G$1" pin="C"/>
<wire x1="5.08" y1="-76.2" x2="5.08" y2="-78.74" width="0.1524" layer="91"/>
<pinref part="LED2" gate="G$1" pin="C"/>
<wire x1="5.08" y1="-78.74" x2="12.7" y2="-78.74" width="0.1524" layer="91"/>
<wire x1="12.7" y1="-78.74" x2="12.7" y2="-76.2" width="0.1524" layer="91"/>
<pinref part="LED3" gate="G$1" pin="C"/>
<wire x1="20.32" y1="-76.2" x2="20.32" y2="-78.74" width="0.1524" layer="91"/>
<wire x1="20.32" y1="-78.74" x2="12.7" y2="-78.74" width="0.1524" layer="91"/>
<junction x="12.7" y="-78.74"/>
<pinref part="LEDPUTIH" gate="G$1" pin="C"/>
<wire x1="27.94" y1="-76.2" x2="27.94" y2="-78.74" width="0.1524" layer="91"/>
<wire x1="27.94" y1="-78.74" x2="20.32" y2="-78.74" width="0.1524" layer="91"/>
<junction x="20.32" y="-78.74"/>
<wire x1="12.7" y1="-78.74" x2="12.7" y2="-83.82" width="0.1524" layer="91"/>
<label x="12.7" y="-83.82" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="A4"/>
<wire x1="-20.32" y1="-104.14" x2="-20.32" y2="-109.22" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="-109.22" x2="-15.24" y2="-109.22" width="0.1524" layer="91"/>
<label x="-17.78" y="-109.22" size="1.778" layer="95"/>
</segment>
</net>
<net name="A5" class="0">
<segment>
<pinref part="LEDMERAH" gate="G$1" pin="C"/>
<wire x1="-2.54" y1="-76.2" x2="-2.54" y2="-83.82" width="0.1524" layer="91"/>
<label x="-2.54" y="-83.82" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="A5"/>
<wire x1="-17.78" y1="-104.14" x2="-17.78" y2="-106.68" width="0.1524" layer="91"/>
<wire x1="-17.78" y1="-106.68" x2="-15.24" y2="-106.68" width="0.1524" layer="91"/>
<label x="-17.78" y="-106.68" size="1.778" layer="95"/>
</segment>
</net>
<net name="VIN" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="VIN"/>
<wire x1="-35.56" y1="-104.14" x2="-35.56" y2="-106.68" width="0.1524" layer="91"/>
<wire x1="-35.56" y1="-106.68" x2="-30.48" y2="-106.68" width="0.1524" layer="91"/>
<label x="-33.02" y="-106.68" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$3" gate="G$1" pin="12V"/>
<pinref part="U$6" gate="G$1" pin="OUT+"/>
<wire x1="-73.66" y1="-22.86" x2="-93.98" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="-93.98" y1="-22.86" x2="-111.76" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="-93.98" y1="-22.86" x2="-93.98" y2="-30.48" width="0.1524" layer="91"/>
<junction x="-93.98" y="-22.86"/>
<wire x1="-93.98" y1="-30.48" x2="-86.36" y2="-30.48" width="0.1524" layer="91"/>
<label x="-91.44" y="-30.48" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<pinref part="BUZZER" gate="G$1" pin="2"/>
<wire x1="-17.78" y1="-33.02" x2="-22.86" y2="-33.02" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="D2"/>
<wire x1="-22.86" y1="-33.02" x2="-22.86" y2="-50.8" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>

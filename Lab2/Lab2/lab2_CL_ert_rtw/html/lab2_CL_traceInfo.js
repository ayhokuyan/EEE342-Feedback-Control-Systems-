function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Data Type Conversion1 */
	this.urlHashMap["lab2_CL:22"] = "lab2_CL.c:187,196";
	/* <Root>/Gc */
	this.urlHashMap["lab2_CL:23"] = "lab2_CL.c:218,377,484&lab2_CL.h:172,177,182,220,223,226&lab2_CL_data.c:47,50,53";
	/* <Root>/Sum */
	this.urlHashMap["lab2_CL:24"] = "lab2_CL.c:214&lab2_CL.h:155";
	/* <Root>/Transmit to Computer */
	this.urlHashMap["lab2_CL:25"] = "lab2_CL.c:170,171,195,197,444,457,492,493,499&lab2_CL.h:161,165";
	/* <Root>/Voltage
Source */
	this.urlHashMap["lab2_CL:26"] = "lab2_CL.c:204,212&lab2_CL.h:211,214,217&lab2_CL_data.c:38,41,44";
	/* <S1>/CPR */
	this.urlHashMap["lab2_CL:3"] = "lab2_CL.c:163&lab2_CL.h:205&lab2_CL_data.c:32";
	/* <S1>/Data Type Conversion */
	this.urlHashMap["lab2_CL:4"] = "lab2_CL.c:165";
	/* <S1>/Encoder */
	this.urlHashMap["lab2_CL:5"] = "lab2_CL.c:157,340,472&lab2_CL.h:156,162,259,262,265&lab2_CL_data.c:86,89,92";
	/* <S1>/Product */
	this.urlHashMap["lab2_CL:18"] = "lab2_CL.c:162";
	/* <S1>/Saturation */
	this.urlHashMap["lab2_CL:19"] = "lab2_CL.c:222,231&lab2_CL.h:229,232&lab2_CL_data.c:56,59";
	/* <S1>/min x sampling freq */
	this.urlHashMap["lab2_CL:20"] = "lab2_CL.c:164&lab2_CL.h:202&lab2_CL_data.c:29";
	/* <S2>/Abs */
	this.urlHashMap["lab2_CL:8"] = "lab2_CL.c:267";
	/* <S2>/Clock */
	this.urlHashMap["lab2_CL:10"] = "lab2_CL.c:268";
	/* <S2>/Gain1 */
	this.urlHashMap["lab2_CL:12"] = "lab2_CL.c:233&lab2_CL.h:235&lab2_CL_data.c:62";
	/* <S2>/MATLAB Function */
	this.urlHashMap["lab2_CL:13"] = "lab2_CL.c:266,281";
	/* <S2>/Saturation */
	this.urlHashMap["lab2_CL:15"] = "lab2_CL.c:283,294&lab2_CL.h:244,247&lab2_CL_data.c:71,74";
	/* <S2>/Step */
	this.urlHashMap["lab2_CL:16"] = "lab2_CL.c:311,319&lab2_CL.h:250,253,256&lab2_CL_data.c:77,80,83";
	/* <S3>/Data Type Conversion */
	this.urlHashMap["lab2_CL:9:11"] = "lab2_CL.c:321,332";
	/* <S3>/Digital Output */
	this.urlHashMap["lab2_CL:9:12"] = "lab2_CL.c:334,335,467,510,511,517&lab2_CL.h:164,167";
	/* <S4>/Data Type Conversion */
	this.urlHashMap["lab2_CL:11:11"] = "lab2_CL.c:248,259";
	/* <S4>/Digital Output */
	this.urlHashMap["lab2_CL:11:12"] = "lab2_CL.c:261,262,459,501,502,508&lab2_CL.h:163,166";
	/* <S5>:1 */
	this.urlHashMap["lab2_CL:13:1"] = "lab2_CL.c:270";
	/* <S5>:1:3 */
	this.urlHashMap["lab2_CL:13:1:3"] = "lab2_CL.c:271";
	/* <S5>:1:4 */
	this.urlHashMap["lab2_CL:13:1:4"] = "lab2_CL.c:273";
	/* <S5>:1:5 */
	this.urlHashMap["lab2_CL:13:1:5"] = "lab2_CL.c:276";
	/* <S5>:1:6 */
	this.urlHashMap["lab2_CL:13:1:6"] = "lab2_CL.c:277";
	/* <S6>/Data Type Conversion */
	this.urlHashMap["lab2_CL:14:114"] = "lab2_CL.c:285,289,296";
	/* <S6>/PWM */
	this.urlHashMap["lab2_CL:14:215"] = "lab2_CL.c:307,464&lab2_CL.h:199&lab2_CL_data.c:26";
	/* <S7>/Constant */
	this.urlHashMap["lab2_CL:17:269"] = "lab2_CL.c:237&lab2_CL.h:208&lab2_CL_data.c:35";
	/* <S7>/Constant1 */
	this.urlHashMap["lab2_CL:17:270"] = "lab2_CL.c:238&lab2_CL.h:238&lab2_CL_data.c:65";
	/* <S7>/Switch */
	this.urlHashMap["lab2_CL:17:271"] = "lab2_CL.c:236,246&lab2_CL.h:241&lab2_CL_data.c:68";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "lab2_CL"};
	this.sidHashMap["lab2_CL"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "lab2_CL:1"};
	this.sidHashMap["lab2_CL:1"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "lab2_CL:6"};
	this.sidHashMap["lab2_CL:6"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "lab2_CL:9"};
	this.sidHashMap["lab2_CL:9"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "lab2_CL:11"};
	this.sidHashMap["lab2_CL:11"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<S5>"] = {sid: "lab2_CL:13"};
	this.sidHashMap["lab2_CL:13"] = {rtwname: "<S5>"};
	this.rtwnameHashMap["<S6>"] = {sid: "lab2_CL:14"};
	this.sidHashMap["lab2_CL:14"] = {rtwname: "<S6>"};
	this.rtwnameHashMap["<S7>"] = {sid: "lab2_CL:17"};
	this.sidHashMap["lab2_CL:17"] = {rtwname: "<S7>"};
	this.rtwnameHashMap["<Root>/DC Motor Plant"] = {sid: "lab2_CL:1"};
	this.sidHashMap["lab2_CL:1"] = {rtwname: "<Root>/DC Motor Plant"};
	this.rtwnameHashMap["<Root>/Data Type Conversion1"] = {sid: "lab2_CL:22"};
	this.sidHashMap["lab2_CL:22"] = {rtwname: "<Root>/Data Type Conversion1"};
	this.rtwnameHashMap["<Root>/Gc"] = {sid: "lab2_CL:23"};
	this.sidHashMap["lab2_CL:23"] = {rtwname: "<Root>/Gc"};
	this.rtwnameHashMap["<Root>/Sum"] = {sid: "lab2_CL:24"};
	this.sidHashMap["lab2_CL:24"] = {rtwname: "<Root>/Sum"};
	this.rtwnameHashMap["<Root>/Transmit to Computer"] = {sid: "lab2_CL:25"};
	this.sidHashMap["lab2_CL:25"] = {rtwname: "<Root>/Transmit to Computer"};
	this.rtwnameHashMap["<Root>/Voltage Source"] = {sid: "lab2_CL:26"};
	this.sidHashMap["lab2_CL:26"] = {rtwname: "<Root>/Voltage Source"};
	this.rtwnameHashMap["<S1>/Voltage (V)"] = {sid: "lab2_CL:2"};
	this.sidHashMap["lab2_CL:2"] = {rtwname: "<S1>/Voltage (V)"};
	this.rtwnameHashMap["<S1>/CPR"] = {sid: "lab2_CL:3"};
	this.sidHashMap["lab2_CL:3"] = {rtwname: "<S1>/CPR"};
	this.rtwnameHashMap["<S1>/Data Type Conversion"] = {sid: "lab2_CL:4"};
	this.sidHashMap["lab2_CL:4"] = {rtwname: "<S1>/Data Type Conversion"};
	this.rtwnameHashMap["<S1>/Encoder"] = {sid: "lab2_CL:5"};
	this.sidHashMap["lab2_CL:5"] = {rtwname: "<S1>/Encoder"};
	this.rtwnameHashMap["<S1>/Motorpwm"] = {sid: "lab2_CL:6"};
	this.sidHashMap["lab2_CL:6"] = {rtwname: "<S1>/Motorpwm"};
	this.rtwnameHashMap["<S1>/Product"] = {sid: "lab2_CL:18"};
	this.sidHashMap["lab2_CL:18"] = {rtwname: "<S1>/Product"};
	this.rtwnameHashMap["<S1>/Saturation"] = {sid: "lab2_CL:19"};
	this.sidHashMap["lab2_CL:19"] = {rtwname: "<S1>/Saturation"};
	this.rtwnameHashMap["<S1>/min x sampling freq"] = {sid: "lab2_CL:20"};
	this.sidHashMap["lab2_CL:20"] = {rtwname: "<S1>/min x sampling freq"};
	this.rtwnameHashMap["<S1>/Velocity (rpm)"] = {sid: "lab2_CL:21"};
	this.sidHashMap["lab2_CL:21"] = {rtwname: "<S1>/Velocity (rpm)"};
	this.rtwnameHashMap["<S2>/In1"] = {sid: "lab2_CL:7"};
	this.sidHashMap["lab2_CL:7"] = {rtwname: "<S2>/In1"};
	this.rtwnameHashMap["<S2>/Abs"] = {sid: "lab2_CL:8"};
	this.sidHashMap["lab2_CL:8"] = {rtwname: "<S2>/Abs"};
	this.rtwnameHashMap["<S2>/Brake"] = {sid: "lab2_CL:9"};
	this.sidHashMap["lab2_CL:9"] = {rtwname: "<S2>/Brake"};
	this.rtwnameHashMap["<S2>/Clock"] = {sid: "lab2_CL:10"};
	this.sidHashMap["lab2_CL:10"] = {rtwname: "<S2>/Clock"};
	this.rtwnameHashMap["<S2>/Direction "] = {sid: "lab2_CL:11"};
	this.sidHashMap["lab2_CL:11"] = {rtwname: "<S2>/Direction "};
	this.rtwnameHashMap["<S2>/Gain1"] = {sid: "lab2_CL:12"};
	this.sidHashMap["lab2_CL:12"] = {rtwname: "<S2>/Gain1"};
	this.rtwnameHashMap["<S2>/MATLAB Function"] = {sid: "lab2_CL:13"};
	this.sidHashMap["lab2_CL:13"] = {rtwname: "<S2>/MATLAB Function"};
	this.rtwnameHashMap["<S2>/PWM"] = {sid: "lab2_CL:14"};
	this.sidHashMap["lab2_CL:14"] = {rtwname: "<S2>/PWM"};
	this.rtwnameHashMap["<S2>/Saturation"] = {sid: "lab2_CL:15"};
	this.sidHashMap["lab2_CL:15"] = {rtwname: "<S2>/Saturation"};
	this.rtwnameHashMap["<S2>/Step"] = {sid: "lab2_CL:16"};
	this.sidHashMap["lab2_CL:16"] = {rtwname: "<S2>/Step"};
	this.rtwnameHashMap["<S2>/hardlim"] = {sid: "lab2_CL:17"};
	this.sidHashMap["lab2_CL:17"] = {rtwname: "<S2>/hardlim"};
	this.rtwnameHashMap["<S3>/In1"] = {sid: "lab2_CL:9:7"};
	this.sidHashMap["lab2_CL:9:7"] = {rtwname: "<S3>/In1"};
	this.rtwnameHashMap["<S3>/Data Type Conversion"] = {sid: "lab2_CL:9:11"};
	this.sidHashMap["lab2_CL:9:11"] = {rtwname: "<S3>/Data Type Conversion"};
	this.rtwnameHashMap["<S3>/Digital Output"] = {sid: "lab2_CL:9:12"};
	this.sidHashMap["lab2_CL:9:12"] = {rtwname: "<S3>/Digital Output"};
	this.rtwnameHashMap["<S4>/In1"] = {sid: "lab2_CL:11:7"};
	this.sidHashMap["lab2_CL:11:7"] = {rtwname: "<S4>/In1"};
	this.rtwnameHashMap["<S4>/Data Type Conversion"] = {sid: "lab2_CL:11:11"};
	this.sidHashMap["lab2_CL:11:11"] = {rtwname: "<S4>/Data Type Conversion"};
	this.rtwnameHashMap["<S4>/Digital Output"] = {sid: "lab2_CL:11:12"};
	this.sidHashMap["lab2_CL:11:12"] = {rtwname: "<S4>/Digital Output"};
	this.rtwnameHashMap["<S5>:1"] = {sid: "lab2_CL:13:1"};
	this.sidHashMap["lab2_CL:13:1"] = {rtwname: "<S5>:1"};
	this.rtwnameHashMap["<S5>:1:3"] = {sid: "lab2_CL:13:1:3"};
	this.sidHashMap["lab2_CL:13:1:3"] = {rtwname: "<S5>:1:3"};
	this.rtwnameHashMap["<S5>:1:4"] = {sid: "lab2_CL:13:1:4"};
	this.sidHashMap["lab2_CL:13:1:4"] = {rtwname: "<S5>:1:4"};
	this.rtwnameHashMap["<S5>:1:5"] = {sid: "lab2_CL:13:1:5"};
	this.sidHashMap["lab2_CL:13:1:5"] = {rtwname: "<S5>:1:5"};
	this.rtwnameHashMap["<S5>:1:6"] = {sid: "lab2_CL:13:1:6"};
	this.sidHashMap["lab2_CL:13:1:6"] = {rtwname: "<S5>:1:6"};
	this.rtwnameHashMap["<S6>/In1"] = {sid: "lab2_CL:14:116"};
	this.sidHashMap["lab2_CL:14:116"] = {rtwname: "<S6>/In1"};
	this.rtwnameHashMap["<S6>/Data Type Conversion"] = {sid: "lab2_CL:14:114"};
	this.sidHashMap["lab2_CL:14:114"] = {rtwname: "<S6>/Data Type Conversion"};
	this.rtwnameHashMap["<S6>/PWM"] = {sid: "lab2_CL:14:215"};
	this.sidHashMap["lab2_CL:14:215"] = {rtwname: "<S6>/PWM"};
	this.rtwnameHashMap["<S7>/n"] = {sid: "lab2_CL:17:268"};
	this.sidHashMap["lab2_CL:17:268"] = {rtwname: "<S7>/n"};
	this.rtwnameHashMap["<S7>/Constant"] = {sid: "lab2_CL:17:269"};
	this.sidHashMap["lab2_CL:17:269"] = {rtwname: "<S7>/Constant"};
	this.rtwnameHashMap["<S7>/Constant1"] = {sid: "lab2_CL:17:270"};
	this.sidHashMap["lab2_CL:17:270"] = {rtwname: "<S7>/Constant1"};
	this.rtwnameHashMap["<S7>/Switch"] = {sid: "lab2_CL:17:271"};
	this.sidHashMap["lab2_CL:17:271"] = {rtwname: "<S7>/Switch"};
	this.rtwnameHashMap["<S7>/a"] = {sid: "lab2_CL:17:272"};
	this.sidHashMap["lab2_CL:17:272"] = {rtwname: "<S7>/a"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();

;*******************************************************************
;* Punishments
;*******************************************************************
[procedure-DeletePunishment]
	Message=You have decided not to complete your {$zzMaster}'s punishment. Your merits will not be returned to you, and you will loose additional merits.
	AddMerits=-10

[procedure-CleanEquipment]
	Question=CleanEquipment
	
[procedure-AskCum]
	question=AskCum

[question-AskCum]
	Phrase=Did you cum?
	?Yes=CumPunish
	?No=*
	
[procedure-CumPunish]
	message=This is VERY disappointing and defeats the whole purpose of my training. I will give you a severe punishment and set your merits to 0.
	;Option - Merits revert to 0 instead of 500
	;set#=#deltamerits,0
	;OPtion- Subtract starting merits from current merits.
	;subtract#=#deltamerits,#zzmerits
	;Option - Punishment
	procedure=BadOrgasm
	punish=#zzmerits
	PunishmentGroup=wanker
	;Option - Set merits to 0
	SetMerits=0

[question-CleanEquipment]
	Phrase=Did you clean your equipment and put it away properly?
	?No=NoCare
	?Yes=*

[procedure-NoCare]
	message=A sub's equipment is precious to them. This is a serious offense, you will be punished severly.
	AddMerit=-50
	punish=100

[status-Punishment]
	Substatus=0
	StartFlag=PunishmentCamera

[flag-PunishmentCamera]
	if=#Webcam=1
	PointCamera=Point the camera where you will be doing your punishment.
	CameraInterval=00:01,00:10

;*******************************************************************
;* Orgasm Without Permission
;*******************************************************************

[punishment-You will go without touching AT ALL for ANY purpose for # days]
	group=wanker
	GroupOnly=1
	ValueUnit=day
	value=10
	maxpunishment=100
	Forbid=Have an orgasm
	Text=You will wear a chastity device if you have one.
	Text=You are forbidden to touch yourself at all for any purpose for # day(s). | Duration: {!zzMinTime} | Completed: {!zzRunTime}
	
[punishment-You will be denied permission to cum for the next # days]
	group=wanker
	GroupOnly=1
	value=10
	ValueUnit=day	
	Forbid=Have an orgasm
	Text=You will wear a chastity device if you have one.
	Text=You are denied permission to cum. | Duration: {!zzMinTime} | Completed: {!zzRunTime}

;*******************************************************************
;* Written Punishments
;*******************************************************************
[punishment-Write # times:]
	Respit=7d
   	value=1
   	max=100
   	NewStatus=Punishment
	MustStart=1
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	type=lines
	select=random
	line=I promise that I will always do the best to behave.
	line=I promise that I will always do my best to be a good slave.
	line=I promise to always be a good and obedient slave.
	line=I am very sorry that I have not been a good slave.
	line=I will obey my Mistress.
	line=My highest wish is to be a good slave.
	line=I want to be the best slave I can be.
	line=I will always obey any order without hesitation.
	line=I am very proud to be your slave.
	line=I will obey any order you give me.
	line=I will come immediately when You call.
	line=Your wish is my command.
	line=I am your slave, I will always obey you.
	line=I will never do anything without asking permission first.
	line=I will serve to the best of my abilities.

;*******************************************************************
;* Sadistic Punishments
;*******************************************************************
[punishment-Tease yourself with a vibrator for # minutes DO NOT CUM]
	Respit=7d
	value=1
   	ValueUnit=minute
   	max=60
   	NewStatus=Punishment
   	Text=Tease yourself with a vibrator. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MinTimeProcedure=Time-up
	MustStart=1
	Accumulative=1
	PunishmentDone=AskCum
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	
[punishment-Insert a vibrator into your ass for # minutes DO NOT CUM]
	Respit=7d
	value=1
   	ValueUnit=minute
   	max=60
   	NewStatus=Punishment
   	Text=Insert a vibrator into your ass. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MinTimeProcedure=Time-up
	MustStart=1
	Accumulative=1
	PunishmentDone=AskCum
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment	

[punishment-Spank yourself # times on your butt]
	Respit=7d
	group=pain
	value=2
	min=5
	max=30
	MustStart=1
	StartProcedure=Sound_Whack
	StartFlag=PunishmentCamera
	Accumulative=1
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	
[punishment-Spank yourself # times on your inner thigh]
	Respit=7d
	group=pain
	value=2
	min=5
	max=30
	MustStart=1
	StartProcedure=Sound_Whack
	StartFlag=PunishmentCamera
	Accumulative=1
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment	
	
[punishment-Kneel on rice for # minutes]
	Respit=7d
	group=pain
	value=1
   	ValueUnit=minute
   	max=30
   	NewStatus=Punishment
   	Text=Kneel on rice. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MinTimeProcedure=Time-up
	MustStart=1
	Accumulative=1
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment

[punishment-Tape rice to the bottom of your feet for # minutes]
	Respit=7d
	value=0.5
	ValueUnit=minute
	LongRunning=1
	min=15
	max=120
	Text=Tape rice to the bottom of you feet. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Wear nipple clamps for # minutes]
	Respit=7d
	notif=#eNippleClamps=0
   	value=1
   	ValueUnit=minute
   	LongRunning=1
   	min=15
   	max=60
   	resource=Nipples
   	Text=Wear nipple clamps. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	Accumulative=1
	StartFlag=PunishmentCamera
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Wear clover nipple clamps for # minutes]
	Respit=7d
	notif=#eNippleClamps=0
	notif=#eNippleClampsClover=0
   	value=1.5
   	ValueUnit=minute
   	LongRunning=1
   	min=15
   	max=60
   	resource=Nipples
   	Text=Wear clover nipple clamps. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Wear clover nipple clamps on your ears for # minutes]
	Respit=7d
	notif=#eNippleClamps=0
	notif=#eNippleClampsClover=0
   	value=1.5
   	ValueUnit=hour
   	LongRunning=1
   	min=15
   	max=60
   	resource=Nipples
   	Text=Wear clover nipple clamps on your ears. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Wear clover nipple clamps on your nose for # minutes]
	Respit=7d
	notif=#eNippleClamps=0
	notif=#eNippleClampsClover=0
   	value=1.5
   	ValueUnit=hour
   	LongRunning=1
   	max=2
   	resource=Nipples
   	Text=Wear clover nipple clamps on your nose. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Give yourself # strokes with a belt]
	Respit=7d
	notif=#eBelt=0
	value=5
	max=30
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Whip
	Accumulative=1
   	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Give yourself # strokes with a whip]
	Respit=7d
	notif=#eWhip=0
	value=3
	max=30
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Whip
	Accumulative=1
   	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Give yourself # strokes with a wooden spoon]
	Respit=7d
	value=2
	max=30
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Whack
	Accumulative=1
   	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Give yourself # strokes with a spatula]
	Respit=7d
	value=2
	min=5
	max=30
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Whack
	Accumulative=1
   	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

;*******************************************************************
;* Gag Punishments
;*******************************************************************

[punishment-Wear a ballgag for # minutes]
	Respit=7d
	notif=#pGag=0
	notif=#eGagBall=0
   	value=40
   	ValueUnit=minute
   	LongRunning=1
   	min=30
   	max=120
   	resource=Gag
   	Text=Wear a ballgag. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Gag
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Wear a drool gag for # minutes]
	Respit=7d
	notif=#pGag=0
	notif=#eGagDrool=0
   	value=0.75
   	ValueUnit=minute
   	LongRunning=1
   	min=30
   	max=120
   	resource=Gag
   	Text=Wear a drool gag. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Gag
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Wear a ring gag for # minutes]
	Respit=7d
	notif=#pGag=0
	notif=#eGagRing=0
   	value=0.75
   	ValueUnit=minute
   	LongRunning=1
   	min=30
   	max=120
   	resource=Gag
   	Text=Wear a ring gag. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Gag
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Wear a harness ballgag for # minutes]
	Respit=7d
	notif=#pGag=0
	notif=#eGagBallHarness=0
   	value=1
   	ValueUnit=minute
   	LongRunning=1
   	min=30
   	max=120
   	resource=Gag
   	Text=Wear a harness ballgag. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Gag
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Wear a stuffed gag for # minutes]
	Respit=7d
	notif=#pGag=0
	notif=#eGagStuffed=0
   	value=0.5
   	ValueUnit=minute
   	LongRunning=1
   	min=30
   	max=120
   	resource=Gag
   	Text=Wear a stuffed gag. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Gag
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Wear a panel ballgag for # minutes]
	Respit=7d
	notif=#pGag=0
	notif=#eGagBallPanel=0
   	value=1
   	ValueUnit=minute
   	LongRunning=1
   	min=30
   	max=120
   	resource=Gag
   	Text=Wear a panel ballgag. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Gag
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Wear an inflatable gag for # minutes]
	Respit=7d
	notif=#pGag=0
	notif=#eGagInflatable=0
	value=100
	ValueUnit=minute
	LongRunning=1
	min=30
	max=60
	resource=Gag
	Text=Wear an inflatable gag. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Gag
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Wear a muzzle gag for # minutes]
	Respit=7d
	notif=#pGag=0
	notif=#eGagMuzzle=0
	value=1
	ValueUnit=minute
	LongRunning=1
	min=30
	max=120
	resource=Gag
	Text=Wear a muzzle gag. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Gag
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

;*******************************************************************
;* Humiliations
;*******************************************************************
[punishment-No hot showers for # days]
	Respit=7d
	group=humiliation
	value=25
	Max=7
	LongRunning=1
	ValueUnit=day
	Forbid=Take a hot bath/shower
	Accumulative=1
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	StartFlag=ColdShower
	Text=You may only take cold showers. | Duration: {!zzMinTime} | Completed: {!zzRunTime}

[punishment-Deep throat a dildo for # minutes]
	Respit=7d
	notif=#eDildo=0
	group=humiliation
	value=5
	ValueUnit=minute
	max=5
	resource=Gag
	Text=Deep throat a dildo. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment
	
[punishment-Suck on a dildo for # minutes]
	Respit=7d
	notif=#eDildo=0
	group=humiliation
	value=1
	ValueUnit=minute
	max=30
	resource=Gag
	Text=Suck on a dildo. No teeth!| Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment	
	
[punishment-Fuck your dildo for # minutes do not cum]
	Respit=7d
	notif=#eDildo=0
	group=humiliation
	value=1
	ValueUnit=minute
	max=30
	resource=Gag
	Text=Suck on a dildo. No teeth!| Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment		

[punishment-Sit in the closet for # minutes]
	Respit=7d
	NewStatus=Punishment
	group=humiliation
	value=5
	ValueUnit=minute
	LongRunning=1
	max=30
	Text=Sit in the closet. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment

[punishment-Lick your shoes clean]
	Respit=7d
	group=humiliation
   	value=50
   	ValueUnit=minute
   	LongRunning=0
   	max=1
   	Text=Lick your shoes clean.
   	MustStart=1
	StartFlag=PunishmentCamera
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment

[punishment-Wear clothing of the opposite sex at home for # days]
	Respit=7d
	notif=#CrossDress=0
	group=humiliation
	startflag=crossdressing
   	value=50
   	ValueUnit=day
   	LongRunning=1
   	Text=Only wear clothing of the opposite sex while at home. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment

[punishment-You may not wear clothes at home for # days]
	Respit=7d
	group=forcenaked
   	value=50
   	ValueUnit=day
   	LongRunning=1
   	Text=You may not wear clothes while at home. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment

[punishment-Hump a piece of furniture for # minutes]
	Respit=7d
	group=humiliation
	value=5
	ValueUnit=minute
	max=15
	Text=Hump a piece of furniture. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	NewStatus=Punishment
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment

[punishment-You will not wear any underwear for a day]
	Respit=7d
	group=ForceNaked
	value=5
	ValueUnit=day
	min=1
	max=1
	LongRunning=1
	Text=You are not allowed to wear underwear. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment

[punishment-Stand in the corner # minutes]
	Respit=7d
	group=humiliation
	value=2
   	ValueUnit=minute
   	max=30
   	NewStatus=Punishment
   	Text=Stand in the corner. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MinTimeProcedure=Time-up
	MustStart=1
	Accumulative=1
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment

[punishment-Chain your collar to a post for # minutes]
	Respit=7d
	group=humiliation
	notif=#eCollarAny=0
	value=1.25
	ValueUnit=minute
	min=30
	max=120
   	NewStatus=Punishment
	resource=Collar
	Text=Chain yourself to a post. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartProcedure=Sound_Chain
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-You may only crawl for # minutes]
	Respit=7d
	group=humiliation
	value=90
	ValueUnit=minute
	LongRunning=1
	min=30
	max=1440
	Text=You may only crawl. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment

;*******************************************************************
;* Public Humiliations
;*******************************************************************
[punishment-Chain your collar to a post in public view for # hours]
	notif=#pPublicHumiliation=0
	Respit=7d
	notif=#eCollarAny=0
	value=100
	ValueUnit=hour
	max=2
   	NewStatus=Punishment
	resource=Collar
	Text=Chain yourself to a post in public view. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartProcedure=Sound_Chain
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Bind your hands behind your to a pole or tree in public view for # hours]
	notif=#pPublicHumiliation=0
	Respit=7d
   	value=100
   	ValueUnit=hour
   	LongRunning=1
   	max=4
	NewStatus=Punishment
   	resource=Hands
   	Text=Bind your hands behind you to a pole or tree in public view. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-All punishments must be done on webcam chat]
	notif=#pPublicHumiliation=0
	notif=#Webcam=0
	Respit=7d
   	value=75
   	ValueUnit=day
   	LongRunning=1
   	resource=Webcam
   	Text=All punishments must be done on webcam. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment

;*******************************************************************
;* Bondage
;*******************************************************************
[punishment-Bind yourself with an X-Bar for # minutes]
	notif=#eBarX=0
	Respit=7d
	value=1
	ValueUnit=minute
	NewStatus=Punishment
	min=30
	max=120
	resource=Legs
	Resource=Hands
	Text=You must bind yourself with an X-Bar. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartProcedure=Sound_Chain
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Bind your legs with a spreader bar for # minutes]
	notif=#eBarSpreader=0
	Respit=7d
	value=60
	ValueUnit=minute
	LongRunning=1
	min=30
	max=120
	resource=Legs
	Text=Bind your legs with a spreader bar. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
   	NewStatus=Punishment
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Chain
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Bind your hands with a spreader bar for # minutes]
	notif=#eBarSpreader=0
	Respit=7d
	value=1
	ValueUnit=minute
	LongRunning=1
	min=30
	max=120
	Resource=Hands
	Text=Bind your hands with a spreader bar. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
   	NewStatus=Punishment
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Chain
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Bind your legs for # minutes]
	Respit=7d
	value=1
	ValueUnit=minute
	LongRunning=1
	min=30
	max=120
	resource=Legs
	Text=Shackle your legs together. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
   	NewStatus=Punishment
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Chain
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Bind your hands in front for # minutes]
	Respit=7d
	value=1
	ValueUnit=minute
	LongRunning=1
	min=30
	max=120
	resource=Hands
	Text=Bind your hands together in front. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Chain
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Wear bondage mittens for # minutes]
	Respit=7d
	notif=#eBondageMittens=0
	value=1
	ValueUnit=minute
	LongRunning=1
	min=30
	max=120
	resource=Hands
	Text=Wear bondage mittens. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
   	NewStatus=Punishment
	StartFlag=PunishmentCamera
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Bind your hands in back for # minutes]
	Respit=7d
	value=1
	ValueUnit=minute
	LongRunning=1
	min=30
	max=120
	resource=Hands
	Text=Bind your hands together in back. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
   	NewStatus=Punishment
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Chain
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Bind your hands to your collar for # minutes]
	Respit=7d
	notif=#eCollarAny=0
	value=0.5
	ValueUnit=minute
	LongRunning=1
	min=30
	max=120
	resource=Collar
	resource=Hands
	Text=Bind your hands to your collar in front. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
   	NewStatus=Punishment
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Chain
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Bind your hands to your collar in back for # minutes]
	Respit=7d
	notif=#eCollarAny=0
	value=1.2
	ValueUnit=minute
	LongRunning=1
	min=15
	max=120
	resource=Collar
	resource=Hands
	Text=Bind your hands to your collar in back.  | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
   	NewStatus=Punishment
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Chain
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Hogtie yourself for # minutes]
	Respit=7d
	notif=#pHogtie=0
	value=1.5
	ValueUnit=minute
	min=30
	max=120
   	NewStatus=Punishment
	resource=Hands
	resource=Feet
	Text=Hogtie yourself. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartProcedure=Sound_Chain
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Bind yourself spread-eagle for # minutes]
	Respit=7d
	value=1.1
	ValueUnit=minute
	min=30
	max=120
   	NewStatus=Punishment
	resource=Hands
	resource=Feet
	Text=Bind yourself spread-eagle. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartProcedure=Sound_Chain
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Bind yourself so you may only crawl for # minutes]
	Respit=7d
	value=1.5
	ValueUnit=minute
	LongRunning=1
	min=30
	max=120
	resource=Hands
	resource=Feet
	Text=Bind yourself so you can only crawl. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Chain
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

;*******************************************************************
;* Other Punishments
;*******************************************************************
[punishment-Wear a blindfold for # minutes]
	Respit=7d
	notif=#eBlindfold=0
	value=0.5
	ValueUnit=minute
	LongRunning=1
	min=15
	max=120
	resource=Eyes
	NewStatus=Punishment
	Text=Wear a blindfold. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Wear a hood for # minutes]
	Respit=7d
	notif=#eHood=0
	value=1.2
	ValueUnit=minute
	LongRunning=1
	min=15
	max=120
	resource=Head
	Text=Wear a hood. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Gag
	Accumulative=1
	NewStatus=Punishment
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Insert a small butt plug for # minutes]
	Respit=7d
	notif=#eButtPlug=0
	value=0.1
	ValueUnit=minute
	LongRunning=1
	min=30
	max=1440
	resource=ButtPlug
	Text=Insert a small butt plug. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	Accumulative=1
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	MinTimeProcedure=Time-up
	DoneProcedure=CleanEquipment

[punishment-Insert a large butt plug for # minutes]
	Respit=7d
	notif=#eButtPlugLarge=0
	value=0.2
	ValueUnit=minute
	LongRunning=1
	min=15
	max=120
	resource=ButtPlug
	Text=Insert a large butt plug. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	Accumulative=1
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	MinTimeProcedure=Time-up
	DoneProcedure=CleanEquipment

[punishment-Wear a chastity device for # days]
	Respit=7d
	notif=#eChastityDevice=0
	StartFlag=Chaste
   	value=25
   	ValueUnit=day
   	LongRunning=1
   	resource=Chastity
   	Text=Wear a chastity device. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Chain
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Wear a collar for # days]
	Respit=7d
	notif=#eCollarAny=0
	StartFlag=Collared
   	value=20
	Max=7
   	ValueUnit=day
   	LongRunning=1
   	resource=Collar
   	Text=Wear a collar. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Chain
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

[punishment-Wear a posture collar for # minutes]
	Respit=7d
	notif=#eCollarAny=0
	notif=#eCollarPosture=0
	StartFlag=Collared
   	value=25
   	min=60
	Max=120
   	ValueUnit=minute
   	LongRunning=1
   	resource=Collar
   	Text=Wear a posture collar. | Duration: {!zzMinTime} | Completed: {!zzRunTime}
   	MustStart=1
	StartFlag=PunishmentCamera
	StartProcedure=Sound_Chain
	Accumulative=1
	MinTimeProcedure=Time-up
	DeleteAllowed=1
	DeleteProcedure=DeletePunishment
	DoneProcedure=CleanEquipment

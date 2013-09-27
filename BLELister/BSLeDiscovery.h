//
//  BSLeDiscovery.h
//  BLELister
//
//  Created by Steve Baker on 9/26/13.
//  Copyright (c) 2013 Beepscore LLC. All rights reserved.
//  Portions copyright (C) 2011 Apple Inc. All Rights Reserved.
//
// Abstract: Scan for and discover nearby LE peripherals with the matching service UUID.

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import "LeTemperatureAlarmService.h"



/****************************************************************************/
/*							UI protocols									*/
/****************************************************************************/
@protocol BSLeDiscoveryDelegate <NSObject>
- (void) discoveryDidRefresh;
- (void) discoveryStatePoweredOff;
@end



/****************************************************************************/
/*							Discovery class									*/
/****************************************************************************/
@interface BSLeDiscovery : NSObject

+ (id) sharedInstance;


/****************************************************************************/
/*								UI controls									*/
/****************************************************************************/
@property (nonatomic, assign) id<BSLeDiscoveryDelegate>           discoveryDelegate;
@property (nonatomic, assign) id<LeTemperatureAlarmProtocol>	peripheralDelegate;


/****************************************************************************/
/*								Actions										*/
/****************************************************************************/
- (void) startScanningForUUIDString:(NSString *)uuidString;
- (void) stopScanning;

- (void) connectPeripheral:(CBPeripheral*)peripheral;
- (void) disconnectPeripheral:(CBPeripheral*)peripheral;


/****************************************************************************/
/*							Access to the devices							*/
/****************************************************************************/
@property (retain, nonatomic) NSMutableArray    *foundPeripherals;
@property (retain, nonatomic) NSMutableArray	*connectedServices;	// Array of LeTemperatureAlarmService
@end

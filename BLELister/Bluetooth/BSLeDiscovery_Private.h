//
//  BSLeDiscovery_Private.h
//  BLELister
//
//  Created by Steve Baker on 9/27/13.
//  Copyright (c) 2013 Beepscore LLC. All rights reserved.
//

#import "BSLeDiscovery.h"

/// Expose properties for use by unit tests
/// Declare "private" methods for use by unit tests.
/// Use extension () instead of category (Tests) and import in BSLeDiscovery.m
/// This way, compiler checks for incomplete implementation
/// Reference
/// http://stackoverflow.com/questions/1098550/unit-testing-of-private-methods-in-xcode
/// http://lisles.net/accessing-private-methods-and-properties-in-objc-unit-tests/

@interface BSLeDiscovery () {
}

/// Usually set to singleton [NSNotificationCenter defaultCenter]
/// Unit test can set it to a mock notificationCenter
@property (nonatomic, strong) NSNotificationCenter *notificationCenter;


/**
 * designated initializer
 * @param aCentralManager
 * sets ivar centralManager
 * @param aFoundPeripherals
 * sets property self.foundPeripherals
 * Normally aFoundPeripherals is empty mutable array.
 * Then we can add objects to self.foundPeripherals.
 * If aFoundPeripherals is nil, we won't be able to add objects to self.foundPeripherals.
 * @param aConnectedServices
 * sets property self.connectedServices
 * Normally aConnectedServices is empty mutable array.
 * Then we can add objects to self.connectedServices.
 * If aConnectedServices is nil, we won't be able to add objects to self.connectedServices.
 * @param aNotificationCenter
 * sets property self.notificationCenter
 * @return a BSLeDiscovery, generally used as a singleton
 */
- (instancetype)initWithCentralManager:(CBCentralManager *)aCentralManager
                      foundPeripherals:(NSArray *)aFoundPeripherals
                     connectedServices:(NSMutableArray *)aConnectedServices
                    notificationCenter:(NSNotificationCenter *)aNotificationCenter NS_DESIGNATED_INITIALIZER;

@end

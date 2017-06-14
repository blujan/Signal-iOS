//
//  Copyright (c) 2017 Open Whisper Systems. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <YapDatabase/YapDatabaseViewTransaction.h>

@interface TSDatabaseView : NSObject

extern NSString *TSInboxGroup;
extern NSString *TSArchiveGroup;
extern NSString *TSUnreadIncomingMessagesGroup;
extern NSString *TSSecondaryDevicesGroup;

extern NSString *TSThreadDatabaseViewExtensionName;
extern NSString *TSMessageDatabaseViewExtensionName;
extern NSString *TSThreadOutgoingMessageDatabaseViewExtensionName;
extern NSString *TSUnreadDatabaseViewExtensionName;
extern NSString *TSUnseenDatabaseViewExtensionName;
extern NSString *TSThreadSpecialMessagesDatabaseViewExtensionName;
extern NSString *TSSecondaryDevicesDatabaseViewExtensionName;

+ (BOOL)registerThreadDatabaseView;
+ (BOOL)registerThreadInteractionsDatabaseView;
+ (BOOL)registerThreadOutgoingMessagesDatabaseView;

// Instances of OWSReadTracking for wasRead is NO and shouldAffectUnreadCounts is YES.
//
// Should be used for "unread message counts".
+ (BOOL)registerUnreadDatabaseView;

// Should be used for "unread indicator".
//
// Instances of OWSReadTracking for wasRead is NO.
+ (BOOL)registerUnseenDatabaseView;

+ (BOOL)registerThreadSpecialMessagesDatabaseView;
+ (void)asyncRegisterSecondaryDevicesDatabaseView;

@end

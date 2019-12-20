//
//  Copyright (c) 2020 Open Whisper Systems. All rights reserved.
//

#import "BaseModel.h"

NS_ASSUME_NONNULL_BEGIN

@class OWSStorage;
@class SDSAnyReadTransaction;
@class SDSAnyWriteTransaction;
@class SSKProtoEnvelope;

extern NSNotificationName const kNSNotificationNameMessageProcessingDidFlushQueue;

@interface OWSMessageContentJob : BaseModel

@property (nonatomic, readonly) NSDate *createdAt;
@property (nonatomic, readonly) NSData *envelopeData;
@property (nonatomic, readonly, nullable) NSData *plaintextData;
@property (nonatomic, readonly) BOOL wasReceivedByUD;

- (instancetype)initWithEnvelopeData:(NSData *)envelopeData
                       plaintextData:(NSData *_Nullable)plaintextData
                     wasReceivedByUD:(BOOL)wasReceivedByUD NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithUniqueId:(NSString *)uniqueId NS_UNAVAILABLE;
- (instancetype)initWithGrdbId:(int64_t)grdbId uniqueId:(NSString *)uniqueId NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

// --- CODE GENERATION MARKER

// This snippet is generated by /Scripts/sds_codegen/sds_generate.py. Do not manually edit it, instead run `sds_codegen.sh`.

// clang-format off

- (instancetype)initWithGrdbId:(int64_t)grdbId
                      uniqueId:(NSString *)uniqueId
                       createdAt:(NSDate *)createdAt
                    envelopeData:(NSData *)envelopeData
                   plaintextData:(nullable NSData *)plaintextData
                 wasReceivedByUD:(BOOL)wasReceivedByUD
NS_SWIFT_NAME(init(grdbId:uniqueId:createdAt:envelopeData:plaintextData:wasReceivedByUD:));

// clang-format on

// --- CODE GENERATION MARKER

@property (nonatomic, readonly, nullable) SSKProtoEnvelope *envelope;

@end

#pragma mark -

// This class is used to write incoming (decrypted, unprocessed)
// messages to a durable queue and then process them in batches,
// in the order in which they were received.
@interface OWSBatchMessageProcessor : NSObject

- (void)enqueueEnvelopeData:(NSData *)envelopeData
              plaintextData:(NSData *_Nullable)plaintextData
            wasReceivedByUD:(BOOL)wasReceivedByUD
                transaction:(SDSAnyWriteTransaction *)transaction;

- (BOOL)hasPendingJobsWithTransaction:(SDSAnyReadTransaction *)transaction;

@end

NS_ASSUME_NONNULL_END

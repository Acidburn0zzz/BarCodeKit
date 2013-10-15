//
//  BCKCodeCharacter.h
//  BarCodeKit
//
//  Created by Oliver Drobnik on 8/18/13.
//  Copyright (c) 2013 Oliver Drobnik. All rights reserved.
//

/**
 The seven supported bar types represented by their ASCII values
 */
typedef NS_ENUM(NSUInteger, BCKBarType) {
	/**
	 Bottom Half
	 */
    BCKBarTypeBottomHalf = 44,

	/**
	 A space
	 */
    BCKBarTypeSpace = 48,
	
	/**
	 Full bar
	 */
    BCKBarTypeFull = 49,

	/**
	 Top Two Thirds
	 */
    BCKBarTypeTopTwoThirds = 60,

    /**
	 Centre One Third
	 */
    BCKBarTypeCentreOneThird = 61,
    
	/**
	 Bottom Two Thirds
	 */
    BCKBarTypeBottomTwoThirds = 62,
    
	/**
	 Top Half
	 */
    BCKBarTypeTopHalf = 96
};

/**
 Root class representing a code character. Can be marker, spacing, start/stop, check digits or characters.
 */

@interface BCKCodeCharacter : NSObject

/**
 @name Creating Characters
 */

/**
 Creates a new character with a given bit string and whether it is a marker character.
 @warning This method is deprecated, use - [BCKCodeCharacter initWithBars:isMarker:] instead.
 @param bitString The bit string containing ones and zeroes as `NSString` that encode the character.
 @param isMarker Whether the character acts as a marker or a regular character.
*/
- (instancetype)initWithBitString:(NSString *)bitString isMarker:(BOOL)isMarker;

/**
 Creates a new character with an array of given bars and whether it is a marker character.
 @param barArray The array containing bar types.
 @param isMarker Whether the character acts as a marker or a regular character.
 */
- (instancetype)initWithBars:(NSArray *)barArray isMarker:(BOOL)isMarker;

/**
 @name Creating Bars
 */

+ (BCKBarType)bottomHalfBar;
+ (BCKBarType)spaceBar;
+ (BCKBarType)fullBar;
+ (BCKBarType)topTwoThirdsBar;
+ (BCKBarType)centreOneThirdBar;
+ (BCKBarType)bottomTwoThirdsBar;
+ (BCKBarType)topHalfBar;

/**
 @name Enumerating Bits
 */

/**
 Enumerates the bits of the character's bit string from left to right.
 @warning This method is deprecated, use - [BCKCodeCharacter enumerateBitsUsingBlock:] instead.
 @param block The enumeration block that gets executed for each bit
 */
- (void)enumerateBitsUsingBlock:(void (^)(BCKBarType barType, BOOL isBar, NSUInteger idx, BOOL *stop))block;

/**
 Enumerates the bars of the character's bar string from left to right.
 @param block The enumeration block that gets executed for each bar
 */
- (void)enumerateBarsUsingBlock:(void (^)(BCKBarType barType, BOOL isBar, NSUInteger idx, BOOL *stop))block;

/**
 @name Getting Information about Code Characters
 */

/**
 Whether the receiver is a marker character (as opposed to being a digit or letter).
 */
@property (nonatomic, readonly, getter = isMarker) BOOL marker;

/**
 The bit string representing the character.
 @warning This property is deprecated, use barArray instead.
 */
@property (nonatomic, readonly) NSString *bitString;

/**
 The array of bars representing the character.
 */
@property (nonatomic, readonly) NSArray *barArray;

@end

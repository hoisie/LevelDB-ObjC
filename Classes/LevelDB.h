//
//  LevelDB.h
//
//  Copyright 2011 Pave Labs. 
//  See LICENCE for details.
//

#import <Foundation/Foundation.h>

typedef BOOL (^KeyBlock)(NSString *key);
typedef BOOL (^KeyValueBlock)(NSString *key, id value);

@interface LevelDB : NSObject

@property (nonatomic, retain) NSString *path;

+ (LevelDB *)databaseInLibraryWithName:(NSString *)name;

- (id) initWithPath:(NSString *)path;

- (void) putObject:(id)value forKey:(NSString *)key;

- (id) getObject:(NSString *)key;
- (NSString *) getString:(NSString *)key;
- (NSDictionary *) getDictionary:(NSString *)key;
- (NSArray *) getArray:(NSString *)key;

//iteration methods
- (NSArray *)allKeys;
- (void) iterateKeys:(KeyBlock)block;
- (void) iterate:(KeyValueBlock)block;

//clear methods
- (void) deleteObject:(NSString *)key;
- (void) clear;
- (void) deleteDatabase;

@end

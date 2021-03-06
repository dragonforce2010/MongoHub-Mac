//
//  MHFileExporter.h
//  MongoHub
//
//  Created by Jérôme Lebel on 19/11/2011.
//

#import <Foundation/Foundation.h>
#import <MongoObjCDriver/MongoObjCDriver.h>
#import "MHExporterImporter.h"

@class MODCollection;

@interface MHFileExporter : NSObject <MHImporterExporter>
{
    NSString                    *_exportPath;
    MODCollection               *_collection;
    int64_t                     _ii;
    NSError                     *_error;
    MODJsonKeySortOrder         _jsonKeySortOrder;
    NSUInteger                  _documentProcessedCount;
}

- (instancetype)initWithCollection:(MODCollection *)collection exportPath:(NSString *)exportPath;
- (void)export;

@property (nonatomic, readonly, strong) NSString *exportPath;
@property (nonatomic, readonly, strong) MODCollection *collection;
@property (nonatomic, readwrite, assign) MODJsonKeySortOrder jsonKeySortOrder;

@end

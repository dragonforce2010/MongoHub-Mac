//
//  MHConnectionEditorWindowController.h
//  MongoHub
//
//  Created by Jérôme Lebel on 19/08/2012.
//

#import <Cocoa/Cocoa.h>
@class MHConnectionStore;
@class MHConnectionEditorWindowController;
@class ConnectionsArrayController;

@protocol MHConnectionEditorWindowControllerDelegate <NSObject>
@property (nonatomic, strong, readonly) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, strong, readonly) ConnectionsArrayController *connectionsArrayController;
- (void)connectionWindowControllerDidCancel:(MHConnectionEditorWindowController *)controller;
- (void)connectionWindowControllerDidValidate:(MHConnectionEditorWindowController *)controller;
@end

@interface MHConnectionEditorWindowController : NSWindowController
{
    NSTextField                         *_aliasTextField;
    NSTextField                         *_adminUserTextField;
    NSSecureTextField                   *_adminPasswordTextField;
    NSTextField                         *_hostTextField;
    NSTextField                         *_hostportTextField;
    NSButton                            *_usereplCheckBox;
    NSPopUpButton                       *_singleReplicaSetPopUpButton;
    NSTabView                           *_singleReplicaSetTabView;
    NSTextField                         *_replicaSetNameTextField;
    NSTextField                         *_replicaSetServersTextField;
    NSTextField                         *_shardedClusterServersTextField;
    NSTextField                         *_defaultDatabaseTextField;
    NSButton                            *_useSSLCheckbox;
    NSButton                            *_weakCertificateCheckbox;
    NSButton                            *_useSSHCheckBox;
    NSTextField                         *_sshHostTextField;
    NSTextField                         *_sshPortTextField;
    NSTextField                         *_sshUserTextField;
    NSSecureTextField                   *_sshPasswordTextField;
    NSTextField                         *_sshKeyfileTextField;
    NSButton                            *_selectKeyFileButton;
    NSButton                            *_addSaveButton;
    NSPopUpButton                       *_defaultReadModePopUpButton;
    
    MHConnectionStore                   *_editedConnectionStore;
    MHConnectionStore                   *_connectionStoreDefaultValue;
    BOOL                                _newConnection;
    id<MHConnectionEditorWindowControllerDelegate> _delegate;
}
@property (nonatomic, strong, readwrite) MHConnectionStore *editedConnectionStore;
@property (nonatomic, strong, readwrite) MHConnectionStore *connectionStoreDefaultValue;
@property (nonatomic, assign, readwrite) id<MHConnectionEditorWindowControllerDelegate> delegate;
@property (nonatomic, strong, readonly) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, assign, readonly, getter=isNewConnetion) BOOL newConnection;

- (void)modalForWindow:(NSWindow *)window;

@end
